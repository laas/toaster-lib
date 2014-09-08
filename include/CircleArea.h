// This class define a circle area.

#include "Area.h

class CircleArea : Area
{

private:
    bg::model::point<double, 2, bg::cs::cartesian> center;    // position of the center
    double ray;						      // ray of the circle

public:

    // Constructor
    CircleArea(int areaId, bg::model::point<double, 2, bg::cs::cartesian> areaCenter, double areaRay) : Area(int id);

    // function
    bool isInArea(bg::model::point<double, 2, bg::cs::cartesian> center);

    // accessors, mutators
    bg::model::point<double, 2, bg::cs::cartesian> getCenter();
    void setCenter(bg::model::point<double, 2, bg::cs::cartesian> areaCenter);
    double getRay();
    void setRay(double ray);
};

