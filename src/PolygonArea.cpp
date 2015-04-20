// This class define a rectangle area.

#include "PolygonArea.h"

#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/geometry/geometries/adapted/c_array.hpp>

BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

PolygonArea::PolygonArea(int areaId, double points[][2], unsigned int polySize) : Area(areaId) {
    for (unsigned int i = 0; i < polySize; i++) {
        bg::model::d2::point_xy<double> p(points[i][0], points[i][1]);
        bg::append(polyRelative_, p);
        bg::append(poly_, p);
    }
}

// Function

bool PolygonArea::isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point) {
    boost::tuple<double, double> p = boost::make_tuple(point.get<0>(), point.get<1>());
    return bg::within(p, poly_);
}

// Accessors

bg::model::polygon<bg::model::d2::point_xy<double> > PolygonArea::getPolyRelative() {
    return polyRelative_;
}