// This class define an agent.
// An Agent can be either a Human or a Robot.

#include "Entity.h"

enum Mobility { FULL, LIMITED, WHEELED, NO };

class Agent : public Entity
{

private:
    int hasFreeHand;				// Number of free hands
    Mobility mobility;				// Agent mobility
    //WorldState;				// Each agent has his own worldstate

public:
    std::vector<int> hasObjects;		// Agent might have objects (in hand or not)
    std::map<std::string, Joint> skeleton;      // Map Agent joint name with a joint

    // functions
    bool addObject(int objectId);
    bool removeObject(int objectId);
    bool cleanObject();

    // accessors, mutators
    int getFreeHand();
    void setFreeHand(int nbFreeHand);
    Mobility getMobility();
    void setMobility(Mobility AgentMobility);
};

