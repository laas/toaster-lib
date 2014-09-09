// This class define a movable object.
// i.e. an object that can be moved by an agent.

#include "Object.h"

class MovableObject : public Object
{

private:

    int supportObject;			// Movable object may be on top of other object

public:
    vector<int> graspableBy;		// Define who can grasp this item

    // functions
    void removeAgentGrasper(int agentId);
    bool canGrasp(int agentId);

    // accessors, mutators
    int getSupportObject();
    void setSupportObject(int idObject);

};

