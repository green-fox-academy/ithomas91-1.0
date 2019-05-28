//
// Created by Németh Tamás on 2019-02-26.
//

#ifndef SHELTER_ANIMAL_H
#define SHELTER_ANIMAL_H


#include <string>

class Animal {
    public:
    void heal();
    bool isAdoptable();
    void toString();

protected:
        std::string _name;
        int _healCost;
        bool _isHealthy = false;
};


#endif //SHELTER_ANIMAL_H
