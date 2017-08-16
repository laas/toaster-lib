// This class define a movable object.
// i.e. an object that can be moved by an agent.

#include "MovableObject.h"

// Constructor

MovableObject::MovableObject(std::string id) : Object(id) {
}

// functions

void MovableObject::removeAgentGrasper(std::string agentId) {
    std::vector<std::string>::iterator i = std::find(graspableBy_.begin(), graspableBy_.end(), agentId);
    if (i != graspableBy_.end())
        graspableBy_.erase(i);
}

bool MovableObject::canGrasp(std::string agentId) {
    if (std::find(graspableBy_.begin(), graspableBy_.end(), agentId) != graspableBy_.end())
        return true;
    else
        return false;
}

// accessors, mutators

std::string MovableObject::getSupportObject() {
    return supportObject;
}

void MovableObject::setSupportObject(std::string idObject) {
    supportObject = idObject;
}

std::string MovableObject::getValue()
{
  return value;
}

void MovableObject::setValue(std::string p_value)
{
  value = p_value;
}
