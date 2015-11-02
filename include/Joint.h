// This class define a joint.

#ifndef JOINT_H
#define JOINT_H

#include "Entity.h"

class Joint : public Entity {
private:
    std::string jointOwner; // Agent from which this joint is

public:

    double position; // Angular position of the joint.

    // Constructor
    Joint(std::string jointId, std::string jointOwner);

    // accessors, mutators
    std::string getAgentId();
    void setAgentId(std::string agentId);
};

#endif
