// This class define an area.

#include "Area.h"

// Constructor
Area::Area(int areaId) : id(areaId){
}

// functions
void Area::removeEntity(int entId){
  std::vector<int>::iterator i = std::find(insideEntities_.begin(), insideEntities_.end(), entId);
  if (i != insideEntities_.end())
    insideEntities_.erase(i);
}

bool Area::isIdInArea(int id){
  if( std::find(insideEntities_.begin(), insideEntities_.end(), id) != insideEntities_.end() )
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
