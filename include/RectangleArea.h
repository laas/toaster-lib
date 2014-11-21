// This class define a rectangle area.

#ifndef RECTANGLE_AREA_H
  #define RECTANGLE_AREA_H


#include "Area.h"

class RectangleArea : public Area
{

private:
    double width;	// rectangle width
    double height;	// rectangle height

public:

    std::vector<bg::model::point <double, 2, bg::cs::cartesian> > corners; // rectangle corners

    // Constructor
    RectangleArea(int areaId, std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners);

    // Function
    bool isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point);

    // accessors, mutators
    double getWidth();
    double getHeight();
};

#endif
