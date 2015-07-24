// This class define an object.
// An object can be either a MovableObject or a StaticObject.

#include "Object.h"

// Constructor

Object::Object(std::string id) : Entity(id) {
    setEntityType(OBJECT);
}

// accessors, mutators

std::string Object::getSupportFurniture() {
    return supportFurniture;
}

void Object::setSupportFurniture(std::string idFurniture) {
    supportFurniture = idFurniture;
}

std::string Object::getContainerId() {
    return container;
}

void Object::setContainerId(std::string idContainer) {
    container = idContainer;
}
