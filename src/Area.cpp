// This class define an area.

#include "Area.h"

// Constructor

Area::Area(unsigned int areaId) : id(areaId) {
    myOwner = "";                            //By default an area has no owner
}

// functions
/**
void Area::removeEntity(std::string entId) {
    std::vector<std::string>::iterator i = std::find(insideEntities_.begin(), insideEntities_.end(), entId);
    if (i != insideEntities_.end())
        insideEntities_.erase(i);
}
**/

bool Area::isIdInArea(std::string id) {
    if (std::find(insideEntities_.begin(), insideEntities_.end(), id) != insideEntities_.end())
        return true;
    else
        return false;
}

// accessors, mutators

unsigned int Area::getId() {
    return id;
}

void Area::setId(unsigned int areaId) {
    id = areaId;
}

std::string Area::getMyOwner() {
    return myOwner;
}

void Area::setMyOwner(std::string ownerId) {
    myOwner = ownerId;
}

std::string Area::getName() {
    return name;
}

void Area::setName(std::string areaName) {
    name = areaName;
}

std::string Area::getAreaType() {
    return areaType;
}

void Area::setAreaType(std::string type) {
    areaType = type;
}

std::string Area::getFactType() {
    return factType;
}

void Area::setFactType(std::string myFactType) {
    factType = myFactType;
}

std::string Area::getEntityType() {
    return entityType;
}

void Area::setEntityType(std::string myEntityType) {
    entityType = myEntityType;
}

bool Area::getIsCircle() {
    return isCircle;
}

void Area::setIsCircle(bool circle) {
    isCircle = circle;
}

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
	std::vector<std::string>::iterator i = std::find(insideEntities_.begin(), insideEntities_.end(), EntityID);
    if (i != insideEntities_.end()){
        insideEntities_.erase(i);
        return true;
	}
	else 
		return false;
}

bool Area::removeUpcomingEntity(std::string EntityID){
    std::vector<std::string>::iterator i = std::find(upcomingEntities_.begin(), upcomingEntities_.end(), EntityID);
    if (i != upcomingEntities_.end()){
        upcomingEntities_.erase(i);
        return true;
	}
	else 
		return false;
		
}

bool Area::removeLeavingEntity(std::string EntityID){
	std::vector<std::string>::iterator i = std::find(leavingEntities_.begin(), leavingEntities_.end(), EntityID);
    if (i != leavingEntities_.end()){
        leavingEntities_.erase(i);
        return true;
	}
	else 
		return false;
        		
}

bool Area::isInsideEntity(std::string EntityID){
	std::vector<std::string>::iterator i = std::find(insideEntities_.begin(), insideEntities_.end(), EntityID);
    if (i != insideEntities_.end()){
        return true;
	}
	else 
		return false;
}

bool Area::isLeavingEntity(std::string EntityID){
	std::vector<std::string>::iterator i = std::find(leavingEntities_.begin(), leavingEntities_.end(), EntityID);
    if (i != leavingEntities_.end()){
        return true;
	}
	else 
		return false;
}

bool Area::isUpcomingEntity(std::string EntityID){
    std::vector<std::string>::iterator i = std::find(upcomingEntities_.begin(), upcomingEntities_.end(), EntityID);
    if (i != upcomingEntities_.end()){
        return true;
	}
	else 
		return false;	
}
