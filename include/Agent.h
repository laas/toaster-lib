// This class define an agent.
// An Agent can be either a Human or a Robot.

#ifndef AGENT_H
  #define AGENT_H

  #include "Entity.h"
  #include "Joint.h"

  enum Mobility { FULL, LIMITED, WHEELED, NO };

  class Agent : public Entity
  {

  private:
    Mobility mobility;				// Agent mobility
    //WorldState;				// Each agent has his own worldstate

  public:
    std::vector<unsigned int> freeHands_;		// name of free grasper joints ("hands")
    std::vector<unsigned int> hasObjects_;	// Agent might have objects (in hand or not)
    std::map<std::string, Joint*> skeleton_;     // Map Agent joint name with a joint

    // constructor
    Agent(unsigned int id);
    
    // destructor
    ~Agent();

    // functions
    bool isHandFree(unsigned int hand);
    void removeFreeHand(unsigned int busyHand);
    unsigned int getNbFreeHands();

    // accessors, mutators
    Mobility getMobility();
    void setMobility(Mobility AgentMobility);
  };

#endif
