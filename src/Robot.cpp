// This class define a Robot.

#include "Robot.h"

// constructor

Robot::Robot(std::string id) : Agent(id) {
    setEntityType(ROBOT);
}

// accessors, mutators

double Robot::getMaxSpeed() {
    return maxSpeed;
}

void Robot::setSpeed(double speed) {
    maxSpeed = speed;
}
