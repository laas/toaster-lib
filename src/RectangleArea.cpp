// This class define a rectangle area.

#include "RectangleArea.h"


RectangleArea::RectangleArea(int areaId, std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners) : Area(areaId), corners_(areaCorners){
}

// Function
//TODO
bool RectangleArea::isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point){
  return false;
}

// accessors, mutators
//TODO
double RectangleArea::getWidth(){
  return 5.0;
}

//TODO
double RectangleArea::getHeight(){
  return 5.0;
}
