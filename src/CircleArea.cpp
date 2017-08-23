// class defines circle with height in z direction

#include "CircleArea.h"
#include "Tools/MathFunctions.h"

CircleArea::CircleArea(int areaId, bg::model::point<double, 3, bg::cs::cartesian> areaCenter, double areaRay, double heightInz, double EnterHysteresis, double LeaveHysteresis) :
						Area(areaId),
						center_(areaCenter), centerRelative_(areaCenter),
						ray_(areaRay), height_(heightInz),
						enterHysteresis_(EnterHysteresis), leaveHysteresis_(LeaveHysteresis)
{
}

// checks if given point is in the cylinrical area
bool CircleArea::isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID) {
	double x = point.get<0>();
	double y = point.get<1>();
	double z = point.get<2>();
	bg::model::point<double, 2, bg::cs::cartesian> point2d;
	point2d.set<0>(x);
	point2d.set<1>(y);

	double cx = getCenter().get<0>();
	double cy = getCenter().get<1>();
	double cz = getCenter().get<2>();
	bg::model::point<double, 2, bg::cs::cartesian> center2d;
	center2d.set<0>(cx);
	center2d.set<1>(cy);

	double pointCenterDistance = bg::distance(point2d, center2d);
	double leaveDistance = getRay() + leaveHysteresis_;
	double enterDistance = getRay() - enterHysteresis_;

	double h = getHeight();
	double upLimit = cz + h/2.;
	double downLimit = cz - h/2.;

	bool isOut = (pointCenterDistance > leaveDistance) ||
								(z > upLimit) ||
								(z < downLimit);

	if(isOut)
	{
		removeInsideEntity(entityID);
		removeUpcomingEntity(entityID);
		removeLeavingEntity(entityID);
		return false ;
	}
	else
	{
		bool isInLeaving = (pointCenterDistance <= leaveDistance) &&
												(pointCenterDistance > getRay()) &&
												(z <= upLimit) &&
												(z >= downLimit);
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
			bool isInComming = (pointCenterDistance > enterDistance) &&
													(pointCenterDistance <= getRay()) &&
													(z <= upLimit) &&
													(z >= downLimit);
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
