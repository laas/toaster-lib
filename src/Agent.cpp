// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Agent.h"

// constructor
Agent::Agent(int id) : Entity(id){
}



// Functions
int Agent::getNbFreeHands(){
  return freeHands.size();
}

bool Agent::isHandFree(int hand){
  if( std::find(freeHands.begin(), freeHands.end(), hand) != freeHands.end() )
    return true;
  else
    return false;
}

void Agent::removeFreeHand(int busyHand){
  std::vector<int>::iterator i = std::find(freeHands.begin(), freeHands.end(), busyHand);
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
