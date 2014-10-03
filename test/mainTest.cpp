#include "Human.h"
#include "Robot.h"
#include "RectangleArea.h"


bg::model::point <double, 2, bg::cs::cartesian> convert3dTo2d(bg::model::point<double, 3, bg::cs::cartesian> position){
  bg::model::point <double, 2, bg::cs::cartesian> point2d;
  point2d.set<0>(position.get<0>);
  point2d.set<1>(position.get<1>);

  return point2d;
}

int main(int argc, char *argv[])
  {
  bg::model::point<double, 3, bg::cs::cartesian> position(3.0, 4.0, 0.0);
  bg::model::point <double, 2, bg::cs::cartesian> corner1(2.0, 2.0);
  bg::model::point <double, 2, bg::cs::cartesian> corner2(2.0, 5.0);
  bg::model::point <double, 2, bg::cs::cartesian> corner3(4.0, 5.0);
  bg::model::point <double, 2, bg::cs::cartesian> corner4(4.0, 2.0);
  std::vector<bg::model::point <double, 2, bg::cs::cartesian> > areaCorners;

  areaCorner.push_back(corner1);
  areaCorner.push_back(corner2);
  areaCorner.push_back(corner3);
  areaCorner.push_back(corner4);

  Human greg = new Human(0);
  greg.setName("Greg");
  greg.setPosition(position);

  Human miki = new Human(1);
  miki.setName("Miki");
  position.set<0>(1.0);
  position.set<1>(2.0);
  miki.setPosition(position);

  Robot pr2 = new Robot(10);
  pr2.setName("pr2");
  position.set<0>(0.0);
  position.set<1>(0.0);
  pr2.setPosition(position);

  RectangleArea bedroom(0, areaCorners);

  if(RectangleArea.isInArea(greg.getPosition)
}
