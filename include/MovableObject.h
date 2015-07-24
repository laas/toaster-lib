// This class define a movable object.
// i.e. an object that can be moved by an agent.

#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "Object.h"

class MovableObject : public Object {
private:

    std::string supportObject; // Movable object may be on top of other object

public:
    std::vector<std::string> graspableBy_; // Define who can grasp this item

    // Constructor
    MovableObject(std::string id);

    // functions
    void removeAgentGrasper(std::string agentId);
    bool canGrasp(std::string agentId);

    // accessors, mutators
    std::string getSupportObject();
    void setSupportObject(std::string idObject);

};

#endif
