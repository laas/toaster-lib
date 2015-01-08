// This class define a movable object.
// i.e. an object that can be moved by an agent.

#include "MovableObject.h"

// Constructor

MovableObject::MovableObject(unsigned int id) : Object(id) {
}

// functions

void MovableObject::removeAgentGrasper(int agentId) {
    std::vector<int>::iterator i = std::find(graspableBy_.begin(), graspableBy_.end(), agentId);
    if (i != graspableBy_.end())
        graspableBy_.erase(i);
}

bool MovableObject::canGrasp(int agentId) {
    if (std::find(graspableBy_.begin(), graspableBy_.end(), agentId) != graspableBy_.end())
        return true;
    else
        return false;
}

// accessors, mutators

int MovableObject::getSupportObject() {
    return supportObject;
}

void MovableObject::setSupportObject(int idObject) {
    supportObject = idObject;
}
