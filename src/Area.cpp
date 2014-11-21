// This class define an area.

#include "Area.h"

// Constructor
Area::Area(int areaId) : id(areaId){
}

// functions
void Area::removeEntity(int entId){
  std::vector<int>::iterator i = std::find(insideEntities.begin(), insideEntities.end(), entId);
  if (i != insideEntities.end())
    insideEntities.erase(i);
}

bool Area::isIdInArea(int id){
  if( std::find(insideEntities.begin(), insideEntities.end(), id) != insideEntities.end() )
    return true;
  else
    return false;
}

// accessors, mutators
int Area::getId(){
  return id;
}

void Area::setId(int areaId){
  id = areaId;
}

int Area::getMyOwner(){
  return myOwner;
}

void Area::setMyOwner(int ownerId){
  myOwner = ownerId;
}

std::string Area::getName(){
  return name;
}

void Area::setName(std::string areaName){
  name = areaName;
}
