//
// Created by dkurzaj on 8/23/16.
//

#ifndef TOASTER_LIB_STATICIOTOBJECT_H
#define TOASTER_LIB_STATICIOTOBJECT_H

#include "StaticObject.h"

class StaticIoTObject : public StaticObject{
private:
    std::string value; // The value produced by the object

public:
    // Constructor
    StaticIoTObject(std::string id);

    // accessors, mutators
    std::string getValue();
    void setValue(std::string value);
};

#endif //TOASTER_LIB_STATICIOTOBJECT_H
