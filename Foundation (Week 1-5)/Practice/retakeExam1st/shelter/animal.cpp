//
// Created by Németh Tamás on 2019-02-26.
//

#include <iostream>
#include "animal.h"

void Animal::heal()
{
    _isHealthy = true;
}

bool Animal::isAdoptable()
{

    if(_isHealthy == true){
        return true;
    } else{
        return false;
    }

}

void Animal::toString()
{
    if(isAdoptable() == true){
        std::cout << _name << "is not healthy, and "<< std::to_string(_healCost) << ", and not adoptable."<< std::endl;
    } else {
        std::cout << _name << "is adoptable, and healthy." << std::endl;
    }
}
