// This class define a Robot.

#ifndef ROBOT_H
#define ROBOT_H


#include "Agent.h"

class Robot : public Agent {
private:
    double maxSpeed; // A robot has a maximum speed.
public:

    // constructor
    Robot(std::string id);

    // accessors, mutators
    double getMaxSpeed();
    void setSpeed(double speed);
};

#endif
