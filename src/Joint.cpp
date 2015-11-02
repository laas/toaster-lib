// This class define a joint.

#include "Joint.h"

// Constructor

Joint::Joint(std::string jointId, std::string agent) : Entity(jointId), jointOwner(agent) {
    setEntityType(JOINT);
    position = 0.0;
}

// accessors, mutators

std::string Joint::getAgentId() {
    return jointOwner;
}

void Joint::setAgentId(std::string agentId) {
    jointOwner = agentId;
};

