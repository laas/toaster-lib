// This class define a circle area.

#include "CircleArea.h"


// Constructor
CircleArea::CircleArea(int areaId, bg::model::point<double, 2, bg::cs::cartesian> areaCenter, double areaRay) : id(areaId), center(areaCenter), ray(areaRay){
}

// function
//TODO
bool isInArea(bg::model::point<double, 2, bg::cs::cartesian> point){
  return false;
}

// accessors, mutators
bg::model::point<double, 2, bg::cs::cartesian> getCenter(){
  return center;
}

void setCenter(bg::model::point<double, 2, bg::cs::cartesian> areaCenter){
  center = areaCenter;
}

double getRay(){
  return ray;
}

void setRay(double areaRay){
  ray = areaRay;
}
