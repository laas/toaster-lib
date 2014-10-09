// This class define a joint.

#include "Joint.h"

// Constructor
Joint::Joint(int jointId, int agent) : Entity(jointId), jointOwner(agent){
}

// accessors, mutators
int Joint::getAgentId(){
  return jointOwner;
}

void Joint::setAgentId(int agentId){
  jointOwner = agentId;
};

