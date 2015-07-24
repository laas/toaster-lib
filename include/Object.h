// This class define an object.
// An object can be either a MovableObject or a StaticObject.

#ifndef OBJECT_H
#define OBJECT_H


#include "Entity.h"

class Object : public Entity {
private:
    std::string supportFurniture; // id from supporting furniture if any
    std::string container; // id from object containing current



public:
    std::vector<int> containedObjects_; // List of id from object contained in current
    std::vector<int> aboveObjects_; // List of id from object above current
    std::vector<int> closeObjects_; // List of id from object next to current

    // Constructor
    Object(std::string id);

    // accessors, mutators
    std::string getSupportFurniture();
    void setSupportFurniture(std::string idFurniture);

    std::string getContainerId();
    void setContainerId(std::string idContainer);
};

#endif
