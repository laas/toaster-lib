// This class define a Human.

#include "Human.h"


// constructor

Human::Human(std::string id) : Agent(id) {
    setEntityType(HUMAN);
}


// Functions

int Human::getAge() {
    return age;
}

void Human::setAge(int humanAge) {
    age = humanAge;
}
