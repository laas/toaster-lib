// This class define an area.

#include "Area.h"

// Constructor

Area::Area(unsigned int areaId) : id(areaId) {
    myOwner = "";                            //By default an area has no owner
}

// functions
void Area::removeEntity(std::string entId) {
  removeInsideEntity(entId);
  removeUpcomingEntity(entId);
  removeLeavingEntity(entId);
}

bool Area::isIdInArea(std::string id) {
  return isInsideEntity(id);
}

// accessors, mutators

void Area::addInsideEntity(std::string EntityID) {
	insideEntities_.push_back(EntityID);
}

void Area::addUpcomingEntity(std::string EntityID) {
	upcomingEntities_.push_back(EntityID);
}

void Area::addLeavingEntity(std::string EntityID) {
	leavingEntities_.push_back(EntityID);
}

bool Area::removeInsideEntity(std::string EntityID) {
  return removeFromVector(EntityID, insideEntities_);
}

bool Area::removeUpcomingEntity(std::string EntityID){
  return removeFromVector(EntityID, upcomingEntities_);
}

bool Area::removeLeavingEntity(std::string EntityID){
  return removeFromVector(EntityID, leavingEntities_);
}

bool Area::isInsideEntity(std::string EntityID){
  return findInVector(EntityID, insideEntities_);
}

bool Area::isLeavingEntity(std::string EntityID){
  return findInVector(EntityID, leavingEntities_);
}

bool Area::isUpcomingEntity(std::string EntityID){
  return findInVector(EntityID, upcomingEntities_);
}

bool Area::removeFromVector(std::string id, std::vector<std::string> vect)
{
  std::vector<std::string>::iterator it = std::find(vect.begin(), vect.end(), id);
    if (it != vect.end())
    {
        vect.erase(it);
        return true;
  	}
  	else
  		return false;
}

bool Area::findInVector(std::string id, std::vector<std::string> vect)
{
  if (std::find(vect.begin(), vect.end(), id) != vect.end())
    return true;
  else
    return false;
}
