#include <iostream>
#include "animal.h"

int main() {

    animal animal1;

    animal1.play();
    animal1.play();
    animal1.eat();
    animal1.drink();


std::cout << animal1.hunger << " " << animal1.thirst <<std::endl;

    return 0;
}