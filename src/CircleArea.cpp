// This class define a circle area.

#include "CircleArea.h"


// Constructor
CircleArea::CircleArea(int areaId, bg::model::point<double, 2, bg::cs::cartesian> areaCenter, double areaRay) : Area(areaId), center(areaCenter), ray(areaRay){
}

// function
//TODO
bool CircleArea::isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> point){
  return false;
}

// accessors, mutators
bg::model::point<double, 2, bg::cs::cartesian> CircleArea::getCenter(){
  return center;
}

void CircleArea::setCenter(bg::model::point<double, 2, bg::cs::cartesian> areaCenter){
  center = areaCenter;
}

double CircleArea::getRay(){
  return ray;
}

void CircleArea::setRay(double areaRay){
  ray = areaRay;
}
