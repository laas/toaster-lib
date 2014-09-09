// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Entity.h"

enum Mobility { FULL, LIMITED, WHEELED, NO };

class Agent : public Entity
{

private:
    Mobility mobility;				// Agent mobility
    //WorldState;				// Each agent has his own worldstate

public:
    std::vector<std::string> freeHands;		// name of free grasper joints ("hands")
    std::vector<int> hasObjects;		// Agent might have objects (in hand or not)
    std::map<std::string, Joint> skeleton;      // Map Agent joint name with a joint

    // functions
    bool isHandFree(std::string hand);
    void removeFreeHand(std::string busyHand);
    int getNbFreeHands();

    // accessors, mutators
    Mobility getMobility();
    void setMobility(Mobility AgentMobility);
};

