#include <iostream>

#include "fleet.h"

// Create a fleet of things to have this output:
// 1. [ ] Get milk
// 2. [ ] Remove the obstacles
// 3. [x] Stand up
// 4. [x] Eat lunch


int main(int argc, char* args[])
{
    Fleet fleet;

    Thing obj1("Get milk");
    Thing obj2("Remove the obstacles");
    Thing obj3("Stand up");
    Thing obj4("Eat lunch");

    obj3.complete();
    obj4.complete();

    fleet.add(obj1);
    fleet.add(obj2);
    fleet.add(obj3);
    fleet.add(obj4);



    std::cout << fleet.toString() << std::endl;
    return 0;
}