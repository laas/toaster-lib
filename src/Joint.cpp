// This class define a joint.

#include "Joint.h"

class Joint : public Entity
{

private:
    int jointOwner;	// Agent from which this joint is

public:

// Constructor
Joint::Joint(int jointId, int agent)id(jointId), jointOwner(agent){
}

// accessors, mutators
int getAgentId();
  return jointOwner;
}

void setAgentId(int agentId);
  jointOwner = agentId;
};

