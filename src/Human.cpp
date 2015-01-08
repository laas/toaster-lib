// This class define a Human.

#include "Human.h"


// constructor

Human::Human(int id) : Agent(id) {
}


// Functions

int Human::getAge() {
    return age;
}

void Human::setAge(int humanAge) {
    age = humanAge;
}
