// This class define a joint.

#include "Joint.h"

// Constructor

Joint::Joint(std::string jointId, std::string agent) : Entity(jointId), jointOwner(agent) {
    setEntityType(JOINT);
}

// accessors, mutators

std::string Joint::getAgentId() {
    return jointOwner;
}

void Joint::setAgentId(std::string agentId) {
    jointOwner = agentId;
};

