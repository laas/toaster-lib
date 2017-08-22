//
// Created by dkurzaj on 8/23/16.
//

#ifndef TOASTER_LIB_MOVABLEIOTOBJECT_H
#define TOASTER_LIB_MOVABLEIOTOBJECT_H

#include "MovableObject.h"

class MovableIoTObject : public MovableObject {
private:
    std::string value; // The value produced by the object

public:
    // Constructor
    MovableIoTObject(std::string id);

    // accessors, mutators
    std::string getValue();
    void setValue(std::string value);
};

#endif //TOASTER_LIB_MOVABLEIOTOBJECT_H
