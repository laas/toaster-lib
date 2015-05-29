// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Agent.h"

// constructor

Agent::Agent(unsigned int id) : Entity(id) {
}

// destructor

Agent::~Agent() {
    for (std::map<std::string, Joint*>::iterator it = skeleton_.begin(); it != skeleton_.end(); ++it) {
        delete it->second;
    }
}

// Functions

unsigned int Agent::getNbFreeHands() {
    return freeHands_.size();
}

bool Agent::isHandFree(std::string hand) {
    if (std::find(freeHands_.begin(), freeHands_.end(), hand) != freeHands_.end())
        return true;
    else
        return false;
}

void Agent::removeFreeHand(std::string busyHand) {
    std::vector<std::string>::iterator it = std::find(freeHands_.begin(), freeHands_.end(), busyHand);
    if (it != freeHands_.end())
        freeHands_.erase(it);
}


// accessors, mutators

Mobility Agent::getMobility() {
    return mobility;
}

void Agent::setMobility(Mobility AgentMobility) {
    mobility = AgentMobility;
}
