//
// Created by dkurzaj on 8/23/16.
//

#include "StaticIoTObject.h"

// Constructor

StaticIoTObject::StaticIoTObject(std::string id) : StaticObject(id) {
}

// functions


// accessors, mutators

std::string StaticIoTObject::getValue() {
    return value;
}

void StaticIoTObject::setValue(std::string value) {
    value = value;
}
