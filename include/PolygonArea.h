// This class define a rectangle area.

#ifndef POLYGON_AREA_H
#define POLYGON_AREA_H


#include "Area.h"
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

class PolygonArea : public Area {
private:
    bg::model::polygon<bg::model::d2::point_xy<double> > polyRelative_; //If area updated, this won't be changed


public:
    bg::model::polygon<bg::model::d2::point_xy<double> > poly_;

    // Constructor
    PolygonArea(int areaId, double points[][2], unsigned int polySize);

    // Function
    bool isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point);

    // accessors
    bg::model::polygon<bg::model::d2::point_xy<double> > getPolyRelative();

};

#endif
