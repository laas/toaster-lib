// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Agent.h"

// constructor

Agent::Agent(std::string id) : Entity(id) {
}

// destructor

Agent::~Agent() {
    for (std::map<std::string, Joint*>::iterator it = skeleton_.begin(); it != skeleton_.end(); ++it) {
        delete it->second;
    }
}

// Functions

unsigned int Agent::getNbBusyHands() {
    return busyHands_.size();
}

bool Agent::isHandFree(std::string hand) {
    if (std::find(busyHands_.begin(), busyHands_.end(), hand) != busyHands_.end())
        return false;
    else
        return true;
}

void Agent::removeBusyHand(std::string busyHand) {
    std::vector<std::string>::iterator it = std::find(busyHands_.begin(), busyHands_.end(), busyHand);
    if (it != busyHands_.end())
        busyHands_.erase(it);
}


// accessors, mutators

Mobility Agent::getMobility() {
    return mobility;
}

void Agent::setMobility(Mobility AgentMobility) {
    mobility = AgentMobility;
}
