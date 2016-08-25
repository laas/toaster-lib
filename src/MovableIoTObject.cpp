//
// Created by dkurzaj on 8/23/16.
//

#include "MovableIoTObject.h"

// Constructor

MovableIoTObject::MovableIoTObject(std::string id) : MovableObject(id) {
    printf("New MovableIoTObject : %s", id.c_str());
}

// functions


// accessors, mutators

std::string MovableIoTObject::getValue() {
    return value;
}

void MovableIoTObject::setValue(std::string value) {
    value = value;
}
