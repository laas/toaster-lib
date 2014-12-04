// This class define a movable object.
// i.e. an object that can be moved by an agent.

#ifndef MOVABLE_OBJECT_H
  #define MOVABLE_OBJECT_H

#include "Object.h"

class MovableObject : public Object
{

private:

    int supportObject;			// Movable object may be on top of other object

public:
    std::vector<int> graspableBy_;		// Define who can grasp this item

    // Constructor
    MovableObject(unsigned int id);
    
    // functions
    void removeAgentGrasper(int agentId);
    bool canGrasp(int agentId);

    // accessors, mutators
    int getSupportObject();
    void setSupportObject(int idObject);

};

#endif
