// This class define an object.
// An object can be either a MovableObject or a StaticObject.

#include "Object.h"

// Constructor

Object::Object(unsigned int id) : Entity(id) {
    setEntityType(OBJECT);
}

// accessors, mutators

int Object::getSupportFurniture() {
    return supportFurniture;
}

void Object::setSupportFurniture(unsigned int idFurniture) {
    supportFurniture = idFurniture;
}

int Object::getContainerId() {
    return container;
}

void Object::setContainerId(unsigned int idContainer) {
    container = idContainer;
}
