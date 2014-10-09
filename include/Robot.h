// This class define a Robot.

#include "Agent.h"

class Robot : public Agent
{

private:
    int maxSpeed;	// A robot has a maximum speed.
public:

    // constructor
    Robot(int id);

    // accessors, mutators
    int getMaxSpeed();
    void setSpeed(int speed);
};

