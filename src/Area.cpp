// This class define an area.

#include "Area.h"

// Constructor

Area::Area(unsigned int areaId) : id(areaId) {
    myOwner = "";                            //By default an area has no owner
}

// functions

void Area::removeEntity(std::string entId) {
    std::vector<std::string>::iterator i = std::find(insideEntities_.begin(), insideEntities_.end(), entId);
    if (i != insideEntities_.end())
        insideEntities_.erase(i);
}

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