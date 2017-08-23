// This class define a circle area.

#ifndef CIRCLE_AREA_H
#define CIRCLE_AREA_H

#include "Area.h"

class CircleArea : public Area {
private:
    bg::model::point<double, 3, bg::cs::cartesian> center_; // position of the center
    double ray_; // ray of the circle
    bg::model::point<double, 3, bg::cs::cartesian> centerRelative_; // If area is updated from owner,
                                                                // we may want an offset from this owner
    double height_; // height of the cylinder (circle with height)
    double enterHysteresis_ ;
    double leaveHysteresis_ ;

public:

    // Constructor
    CircleArea(int areaId, bg::model::point<double, 3, bg::cs::cartesian> areaCenter, double areaRay, double heightInz, double EnterHysteresis, double LeaveHysteresis);

    // function
    bool isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID);

    // accessors, mutators
    // If you add accessors or mutators please make them here
    // When you put your function in .h, it will be inline
    // and will increase the performance of your programm
    bg::model::point<double, 3, bg::cs::cartesian> getCenter()                  { return center_; }
    void setCenter(bg::model::point<double, 3, bg::cs::cartesian> areaCenter)   { center_ = areaCenter; }
    double getRay()           { return ray_; }
    void setRay(double ray)   { ray_ = ray; }
    double getHeight()         { return height_; }
    void setHeight(double heightInz)   { height_ = heightInz; }
    bg::model::point<double, 3, bg::cs::cartesian> getCenterRelative()   { return centerRelative_; }
};

#endif
