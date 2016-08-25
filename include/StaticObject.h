// This class define a static object.
// i.e. an object that can't be moved by an agent.

#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H


#include "Object.h"

class StaticObject : public Object
{

private:


public:
    // Constructor
    StaticObject(std::string id);

};

#endif
