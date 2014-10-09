// This class define a joint.

#ifndef JOINT_H
  #define JOINT_H

#include "Entity.h"

class Joint : public Entity
{

private:
    int jointOwner;	// Agent from which this joint is

public:

    // Constructor
    Joint(int jointId, int jointOwner);

    // accessors, mutators
    int getAgentId();
    void setAgentId(int agentId);
};

#endif
