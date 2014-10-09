// This class define a movable object.
// i.e. an object that can be moved by an agent.

#include "MovableObject.h"

// functions
void MovableObject::removeAgentGrasper(int agentId){
  std::vector<int>::iterator i = std::find(graspableBy.begin(), graspableBy.end(), agentId);
  if (i != graspableBy.end())
    graspableBy.erase(i);
}

bool MovableObject::canGrasp(int agentId){
  if( std::find(graspableBy.begin(), graspableBy.end(), agentId) != graspableBy.end() )
    return true;
  else
    return false;
}

// accessors, mutators
int MovableObject::getSupportObject(){
  return supportObject;
}

void MovableObject::setSupportObject(int idObject){
  supportObject = idObject;
}
