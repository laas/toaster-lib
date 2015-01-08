// This class define a Robot.

#include "Robot.h"

// constructor

Robot::Robot(int id) : Agent(id) {
}

// accessors, mutators

int Robot::getMaxSpeed() {
    return maxSpeed;
}

void Robot::setSpeed(int speed) {
    maxSpeed = speed;
}
