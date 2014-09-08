// This class define a Human.

#include "Agent.h"

class Human : public Agent
{

private:
    int age;		// Humans have an age

public:
    // accessors, mutators
    int getAge();
    void setAge(int humanAge);
};

