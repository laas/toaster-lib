// This class define a circle area.

#ifndef CIRCLE_AREA_H
#define CIRCLE_AREA_H

#include "Area.h"

class CircleArea : public Area {
private:
    bg::model::point<double, 3, bg::cs::cartesian> center; // position of the center
    double ray; // ray of the circle
    bg::model::point<double, 3, bg::cs::cartesian> centerRelative; // If area is updated from owner,
                                                                // we may want an offset from this owner
    double height; // height of the cylinder (circle with height)

public:

    // Constructor
    CircleArea(int areaId, bg::model::point<double, 3, bg::cs::cartesian> areaCenter, double areaRay, double heightInz, double EnterHysteresis, double LeaveHysteresis);

    // function
    bool isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID);
    double enterHysteresis ;
    double leaveHysteresis ;
    // accessors, mutators
    bg::model::point<double, 3, bg::cs::cartesian> getCenter();
    void setCenter(bg::model::point<double, 3, bg::cs::cartesian> areaCenter);
    double getRay();
    void setRay(double ray);	
    double getHeight();
    void setHeight(double heightInz);
    bg::model::point<double, 3, bg::cs::cartesian> getCenterRelative();
};

#endif
