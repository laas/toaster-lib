// This class define an area.

#include "Area.h"

// Constructor
Area::Area(int areaId) : id(areaId){
}

// functions
void Area::removeEntity(int entId){
  std::insideEntities<int>::iterator i = std::find(inideEntities.begin(), insideEntities.end(), entId);
  if (i != insideEntities.end())
    insideEntities.erase(i);
}

bool Area::isInArea(int id){
  if( std::find(insideEntities.begin(), insideEntities.end(), id) != insideEntities.end() )
    return true
  else
    return false
}

// accessors, mutators
int Area::getId(){
  return id;
}

void Area::setId(int areaId){
  id = areaId;
}

std::string Area::getName(){
  return name;
}

void Area::setName(std::string areaName){
  name = areaName;
}
