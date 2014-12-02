// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Agent.h"

// constructor
Agent::Agent(unsigned int id) : Entity(id){
}

// destructor
Agent::~Agent(){
    for(std::map<std::string, Joint*>::iterator it = skeleton.begin() ; it != skeleton.end() ; ++it){
        delete it->second;
    }
}

// Functions
unsigned int Agent::getNbFreeHands(){
  return freeHands.size();
}

bool Agent::isHandFree(unsigned int hand){
  if( std::find(freeHands.begin(), freeHands.end(), hand) != freeHands.end() )
    return true;
  else
    return false;
}

void Agent::removeFreeHand(unsigned int busyHand){
  std::vector<unsigned int>::iterator i = std::find(freeHands.begin(), freeHands.end(), busyHand);
  if (i != freeHands.end())
    freeHands.erase(i);
}


// accessors, mutators
Mobility Agent::getMobility(){
  return mobility;
}

void Agent::setMobility(Mobility AgentMobility){
  mobility = AgentMobility;
}
