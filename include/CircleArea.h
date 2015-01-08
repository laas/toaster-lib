// This class define a circle area.

#ifndef CIRCLE_AREA_H
#define CIRCLE_AREA_H

#include "Area.h"

class CircleArea : public Area {
private:
    bg::model::point<double, 2, bg::cs::cartesian> center; // position of the center
    double ray; // ray of the circle

public:

    // Constructor
    CircleArea(int areaId, bg::model::point<double, 2, bg::cs::cartesian> areaCenter, double areaRay);

    // function
    bool isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point);

    // accessors, mutators
    bg::model::point<double, 2, bg::cs::cartesian> getCenter();
    void setCenter(bg::model::point<double, 2, bg::cs::cartesian> areaCenter);
    double getRay();
    void setRay(double ray);
};

#endif
