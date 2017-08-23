// This class define a rectangle area.
#include "PolygonArea.h"

#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/geometry/geometries/adapted/c_array.hpp>
#include <iostream>
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)
using namespace std;

// constructor
PolygonArea::PolygonArea(int areaId, double points[][2], unsigned int polySize, double zmin, double zmax, double enter, double leave) :
    Area(areaId),
    enterHysteresis_(enter+0.0001), leaveHysteresis_(leave+0.0001)
{
    for (unsigned int i = 0; i < polySize; i++) {
        bg::model::d2::point_xy<double> p(points[i][0], points[i][1]);
        bg::append(polyRelative_, p);
        bg::append(poly_, p);
    }
    z = boost::make_tuple(zmin+0.0001 , zmax+0.0001);
    zRelative = boost::make_tuple(zmin+0.0001 , zmax+0.0001);
}

int PolygonArea::isInside(std::vector<point_t> vertex, point_t p)
{
	int i, j, cross = 0;
	for (i = 0, j = vertex.size() - 1; i < vertex.size(); j = i++)
	{
		if (((vertex[i].y > p.y) != (vertex[j].y > p.y)) &&
			(p.x < (vertex[j].x - vertex[i].x) * (p.y - vertex[i].y) / (vertex[j].y - vertex[i].y) + vertex[i].x))
			cross = !cross;
	}
	return cross;
}

std::vector<segement_t> PolygonArea::offsetingPolygon(std::vector<point_t> vertices, double offset)
{
	std::vector<segement_t > segements;
	std::vector<point_t>::const_iterator itNext;

	for (std::vector<point_t>::iterator itVect = vertices.begin(); itVect < vertices.end(); ++itVect)
	{
		double x1 = itVect->x;
		double y1 = itVect->y;

		//find the next point
		if (itVect + 1 == vertices.end())
			itNext = vertices.begin();
		else
			itNext = itVect + 1;

		double a, m, c;
		double x2 = itNext->x;
		double y2 = itNext->y;
		// finds the parameters of line's equations. The equation line has the form a*y = m*x + c. where slope is m/a and intercept is c/a .
		if (x2 != x1)
		{
			a = 1;
			m = (y2 - y1) / (x2 - x1);
			c = y1 - m*x1;
		}
		else
    {
			a = 0;
			m = 1;
			c = -x1;
		}
		if (itVect + 2 == vertices.end())
			itNext = vertices.begin();
		else if (itVect + 1 == vertices.end())
			itNext = vertices.begin() + 1;
		else
			itNext = itVect + 2;

		double x;
		double x3 = itNext->x;
		double y3 = itNext->y;

		if (m == 0)
		{
			if (y3 > c) // shifts the line by changing the intercept to get edge of inner polygon
				c = c + offset;
			else // shifts the line by changing the intercept to get edge of inner polygon
				c = c - offset;
		}
		else //if(m != 0)
		{
			double cTmp;
			x = (a*y3 - c) / m; // x is calculated to find the direction in which line is to be shifted
			// shifts the line by changing the intercept to get edge of inner polygon
			if (x3 > x)
			{
				if (-c / m > 0)
					cTmp = (abs(c / sqrt(m*m + a*a)) + offset)*(sqrt(m*m + a*a));
				else
					cTmp = (abs(c / sqrt(m*m + a*a)) - offset)*(sqrt(m*m + a*a));
			}
			else
			{
				if (-c / m > 0)
					cTmp = (abs(c / sqrt(m*m + a*a)) - offset)*(sqrt(m*m + a*a));
				else
					cTmp = (abs(c / sqrt(m*m + a*a)) + offset)*(sqrt(m*m + a*a));
			}

			if (c < 0)
				cTmp = -cTmp;
			c = cTmp;
		} // end m != 0

		segements.push_back(segement_t(a, m, c));
	} // end for itVect
	return segements;
}

point_t PolygonArea::getIntersect(segement_t seg1, segement_t seg2)
{
	double x, y;
	if (seg1.a != 0 && seg2.a != 0)
	{
		x = ((seg2.c / seg2.a) - (seg1.c / seg1.a)) / ((seg1.m / seg1.a) - (seg2.m / seg2.a));
		y = (seg1.m*x + seg1.c) / seg1.a;
	}
	else
	{
		if (seg1.a == 0)
		{
			x = -seg1.c / seg1.m;
			y = (seg2.m*x + seg2.c) / seg2.a;
		}
		else
		{
			x = -seg2.c / seg2.m;
			y = (seg1.m*x + seg1.c) / seg1.a;
		}
	}
	return point_t(x, y);
}

void PolygonArea::getInOutPoints(std::vector<point_t> scare, std::vector<point_t> base, point_t& in, point_t& out)
{
	vector<int> inPoints;
	vector<int> outPoints;

	for (unsigned int i = 0; i < 4; i++)
	{
		if (isInside(base, scare[i]))
			inPoints.push_back(i);
		else
			outPoints.push_back(i);
	}

	if (inPoints.size() == 1)
	{
		in = scare[inPoints[0]];
		out = scare[(inPoints[0] + 2)%4];
	}
	else
	{
		out = scare[outPoints[0]];
		in = scare[(outPoints[0] + 2) % 4];
	}
}

void PolygonArea::extractVectrices(vector<segement_t> segementsOut, vector<segement_t> segementsIn, vector<point_t> base, vector<point_t>& inner, vector<point_t>& outer)
{
	unsigned int i, j;
	for (i = 0, j = segementsOut.size() - 1; i < segementsOut.size(); j = i++)
	{
		std::vector<point_t> scare;

		scare.push_back(getIntersect(segementsOut[i], segementsOut[j]));
		scare.push_back(getIntersect(segementsOut[i], segementsIn[j]));
		scare.push_back(getIntersect(segementsIn[i], segementsIn[j]));
		scare.push_back(getIntersect(segementsIn[i], segementsOut[j]));

		point_t in(0, 0);
		point_t out(0, 0);
		getInOutPoints(scare, base, in, out);
		inner.push_back(in);
		outer.push_back(out);
	}
}

// check if given point is in 2.5D areas
bool PolygonArea::isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID)
{
  point_t p(point.get<0>(), point.get<1>());
  double zPoint = point.get<2>();
  double zmin = z.get<0>();
  double zmax = z.get<1>();
  std::vector<boost::tuple<double, double> > vertices;
  vector<point_t> polygon;

  // extracts vertices of main polygon into vector
  for (unsigned int i = 0; i != poly_.outer().size(); ++i)
  {
    double x = boost::geometry::get<0>(poly_.outer()[i]);
    double y = boost::geometry::get<1>(poly_.outer()[i]);
    polygon.push_back(point_t(x,y));
  }

  std::vector<segement_t> innerSegments = offsetingPolygon(polygon, enterHysteresis_);
	std::vector<segement_t> outerSegments = offsetingPolygon(polygon, -leaveHysteresis_);

	vector<point_t> enter_poly_;
	vector<point_t> leave_poly_;
	extractVectrices(outerSegments, innerSegments, polygon, enter_poly_, leave_poly_);

  bool isOut = !isInside(leave_poly_, p) &&
							(zPoint > zmax + leaveHysteresis_) &&
							(zPoint < zmin - leaveHysteresis_);

	if(isOut)
	{
		removeInsideEntity(entityID);
		removeUpcomingEntity(entityID);
		removeLeavingEntity(entityID);
		return false ;
	}
	else
	{
		bool isInLeaving = isInside(leave_poly_, p) &&
											!isInside(polygon, p) &&
											(zPoint <= zmax + leaveHysteresis_) &&
											(zPoint > zmax) &&
											(zPoint >= zmin - leaveHysteresis_) &&
											(zPoint < zmin);
		if(isInLeaving)
		{
			if(isInsideEntity(entityID))
			{
				removeInsideEntity(entityID);
				addLeavingEntity(entityID);
				return true;
			}
			else if(isLeavingEntity(entityID))
				return true;
			else if(isUpcomingEntity(entityID))
			{
				removeUpcomingEntity(entityID);
				return false;
			}
			else
				return false;
		}
		else
		{
			bool isInComming = !isInside(enter_poly_, p) &&
													isInside(polygon, p) &&
													(zPoint > zmax + enterHysteresis_) &&
													(zPoint <= zmax) &&
													(zPoint < zmin - enterHysteresis_) &&
													(zPoint >= zmin);
			if(isInComming)
			{
				if(isInsideEntity(entityID))
					return true;
				else if(isLeavingEntity(entityID))
				{
					removeLeavingEntity(entityID);
					addInsideEntity(entityID);
					return true;
				}
				else if(isUpcomingEntity(entityID))
					return false;
				else
				{
					addUpcomingEntity(entityID);
					return false;
				}
			}
			else // isInside
			{
				if(isInsideEntity(entityID))
					return true;
				else
				{
					if(isUpcomingEntity(entityID))
						removeUpcomingEntity(entityID);
					else if(isLeavingEntity(entityID))
						removeLeavingEntity(entityID);

					addInsideEntity(entityID);
					return true;
				}
			} // else isInComming <=> isInside
		} // else isInLeaving
	} // else isOut
}
