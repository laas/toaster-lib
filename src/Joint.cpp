// This class define a joint.

#include "Joint.h"

// Constructor

Joint::Joint(unsigned int jointId, unsigned int agent) : Entity(jointId), jointOwner(agent) {
    setEntityType(JOINT);
}

// accessors, mutators

unsigned int Joint::getAgentId() {
    return jointOwner;
}

void Joint::setAgentId(unsigned int agentId) {
    jointOwner = agentId;
};

