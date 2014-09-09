// This class define a rectangle area.

#include "Area.h"

class RectangleArea : Area
{

private:
    double width;	// rectangle width
    double height;	// rectangle height

public:

    std::vector<bg::model::point <double, 2, bg::cs::cartesian> > corners; // rectangle corners

    // Constructor
    RectangleArea(int areaId, std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners);

    // Function
    bool isInArea(bg::model::point<double, 2, bg::cs::cartesian> point);

    // accessors, mutators
    double getWidth();
    double getHeight();
};

