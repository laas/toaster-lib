// This class define a rectangle area.

#include "Area.h"

class RectangleArea : Area
{

private:
    bg::model::point<double, 2, bg::cs::cartesian> center;                 // position of the center
    double width;					                   // rectangle width
    double height;					                   // rectangle height

public:

    std::vector<bg::model::point <double, 2, bg::cs::cartesian> > corners; // rectangle corners

    // Constructor
    RectangleArea(int areaId, std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners) : Area(int id);

    // Function
    bool isInArea(bg::model::point<double, 2, bg::cs::cartesian> center);

    // accessors, mutators
    bg::model::point<double, 2, bg::cs::cartesian> getCenter();
    void setCenter(bg::model::point<double, 2, bg::cs::cartesian> areaCenter);
    double getWidth();
    double getHeight();
};

