// This class define a Robot.

#include "Agent.h"

class Robot : public Agent
{

private:
    int maxSpeed;	// A robot has a maximum speed.
public:
    // accessors, mutators
    int getSpeed();
    void setSpeed(int speed);
};

