// This class define a rectangle area.

#ifndef POLYGON_AREA_H
#define POLYGON_AREA_H

#include "Area.h"
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

struct point_t
{
	double x;
	double y;
	point_t(double X, double Y) : x(X), y(Y) {}
};

struct segement_t
{
	double a;
	double m;
	double c;
	segement_t(double A, double M, double C) : a(A), m(M), c(C) {}
};

class PolygonArea : public Area {
public:

    bg::model::polygon<bg::model::d2::point_xy<double> > poly_;
    boost::tuple<double, double> z; // (zmin, zmax)

    // Constructor
    PolygonArea(int areaId, double points[][2], unsigned int polySize, double zmin, double zmax, double enter, double leave);
    double enterHysteresis_ ;
    double leaveHysteresis_ ;
    // Function
    bool isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID);

    // accessors
    bg::model::polygon<bg::model::d2::point_xy<double> > getPolyRelative() { return polyRelative_; }
    boost::tuple<double,double> getZRelative() { return zRelative ; }
    double getZmin() { return z.get<0>(); }
    double getZmax() { return z.get<1>(); }

private:
    bg::model::polygon<bg::model::d2::point_xy<double> > polyRelative_; //If area updated, this won't be changed
    boost::tuple<double, double> zRelative; // if area is updated it won't

    int isInside(std::vector<point_t> vertex, point_t p);
    std::vector<segement_t> offsetingPolygon(std::vector<point_t> vertices, double offset);
    point_t getIntersect(segement_t seg1, segement_t seg2);
    void getInOutPoints(std::vector<point_t> scare, std::vector<point_t> base, point_t& in, point_t& out);
    void extractVectrices(std::vector<segement_t> segementsOut, std::vector<segement_t> segementsIn, std::vector<point_t> base, std::vector<point_t>& inner, std::vector<point_t>& outer);
};

#endif
