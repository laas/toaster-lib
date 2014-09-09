// This class define a rectangle area.

#include "RectangleArea.h"


RectangleArea::RectangleArea(int areaId, std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners) : id(areaId), corners(areaCorners){
}

// Function
//TODO
bool RectangleArea::isInArea(bg::model::point<double, 2, bg::cs::cartesian> point){
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
