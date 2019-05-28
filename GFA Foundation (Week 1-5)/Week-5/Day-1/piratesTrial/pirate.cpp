//
// Created by Tamas Nemeth on 2019-02-11.
//

#include <iostream>
#include "pirate.h"
Pirate::Pirate(std::string name, bool isCaptain, bool hasWoodenLeg)
{
    _name = name;
    _isCaptain = isCaptain;
    _hasWoodenLeg = hasWoodenLeg;
    _amountOfGold = 0;
    _healthPoint = 10;

}
void Pirate::work()
{
        if(_isCaptain){
            _amountOfGold +=10;
            _healthPoint -=5;
        } else{
            _amountOfGold +=1;
            _healthPoint -=1;
        }
}
void Pirate::party() {
        if(_isCaptain){
            _healthPoint += 10;
         } else {
            _healthPoint++;
        }

}
std::string Pirate::toString() {
    if(_hasWoodenLeg){
       return ("Hello, I'm " + _name + " I have a wooden leg and " + std::to_string(_amountOfGold) + " golds");
    } else {
       return ("Hello, I'm " +_name +". I still have my real legs and " + std::to_string(_amountOfGold) + " golds.");
    }
}
int Pirate::getAmountOfGold() {
    return _amountOfGold;
}
std::string Pirate::getName() {
    return _name;
}
bool Pirate::isCaptain() {
    return _isCaptain;
}
bool Pirate::hasWoodenLeg() {
    return _hasWoodenLeg;
}
