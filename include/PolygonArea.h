// This class define a rectangle area.

#ifndef POLYGON_AREA_H
#define POLYGON_AREA_H


#include "Area.h"
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

class PolygonArea : public Area {
private:
    bg::model::polygon<bg::model::d2::point_xy<double> > polyRelative_; //If area updated, this won't be changed
    boost::tuple<double, double> zRelative; // if area is updated it won't

public:

    bg::model::polygon<bg::model::d2::point_xy<double> > poly_;
    boost::tuple<double, double> z; // (zmin, zmax)

    // Constructor
    PolygonArea(int areaId, double points[][2], unsigned int polySize, double zmin, double zmax, double enter, double leave);
    double enterHysteresis ;
    double leaveHysteresis ;
    // Function
    bool isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID);

    // accessors
    bg::model::polygon<bg::model::d2::point_xy<double> > getPolyRelative();
    boost::tuple<double,double> getZRelative();
    double getZmin();
    double getZmax();

};

#endif
