// This class define a Robot.

#ifndef ROBOT_H
  #define ROBOT_H


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

#endif
