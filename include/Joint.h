// This class define a joint.

#ifndef JOINT_H
  #define JOINT_H

#include "Entity.h"

class Joint : public Entity
{

private:
    unsigned int jointOwner;	// Agent from which this joint is

public:

    // Constructor
    Joint(unsigned int jointId, unsigned int jointOwner);

    // accessors, mutators
    unsigned int getAgentId();
    void setAgentId(unsigned int agentId);
};

#endif
