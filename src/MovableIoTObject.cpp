//
// Created by dkurzaj on 8/23/16.
//

#include "MovableIoTObject.h"

// Constructor

MovableIoTObject::MovableIoTObject(std::string id) : MovableObject(id) {
    printf("New MovableIoTObject : %s\n", id.c_str());
}

// accessors, mutators

std::string MovableIoTObject::getValue() {
    return value;
}

void MovableIoTObject::setValue(std::string newValue) {
    value = newValue;
}
