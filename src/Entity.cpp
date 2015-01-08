// This class define an entity.
// An entity can be either an agent or an object.


#include <Entity.h>
#include <algorithm>

// Constructor

Entity::Entity(unsigned int entityId) : id(entityId) {
}

//functions

bool Entity::isInArea(unsigned int areaId) {
    if (std::find(inArea_.begin(), inArea_.end(), areaId) != inArea_.end())
        return true;
    else
        return false;
}

void Entity::removeInArea(unsigned int areaId) {
    std::vector<unsigned int>::iterator i = std::find(inArea_.begin(), inArea_.end(), areaId);
    if (i != inArea_.end())
        inArea_.erase(i);
}

// accessors, mutators

unsigned int Entity::getId() {
    return id;
}

void Entity::setId(unsigned int entId) {
    id = entId;
}

unsigned long Entity::getTime() {
    return time;
}

void Entity::setTime(unsigned long entTime) {
    time = entTime;
}

std::string Entity::getName() {
    return name;
}

void Entity::setName(std::string entityName) {
    name = entityName;
}

unsigned int Entity::getConfidence() {
    return confidence;
}

void Entity::setConfidence(unsigned int confid) {
    confidence = confid;
}

unsigned int Entity::getRoomId() {
    return roomId;
}

void Entity::setRoomId(unsigned int id) {
    roomId = id;
}

bg::model::point<double, 3, bg::cs::cartesian> Entity::getPosition() {
    return position_;
}

void Entity::setPosition(bg::model::point<double, 3, bg::cs::cartesian> point) {
    position_ = point;
}

std::vector<double> Entity::getOrientation() {
    return orientation_;
}

void Entity::setOrientation(std::vector<double> entityOrientation) {
    orientation_ = entityOrientation;
}
