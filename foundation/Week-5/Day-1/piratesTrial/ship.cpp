//
// Created by Tamas Nemeth on 2019-02-11.
//

#include "ship.h"
#include "pirate.h"

void Ship::addPirate(Pirate onePirate)
{
    if(!onePirate.isCaptain())
    {
        _pirates.push_back(onePirate);
    }
}
std::vector<std::string> Ship::getPoorPirates()
{
    std::vector<std::string> nameOfPirates;

    for (int i = 0; i < _pirates.size(); ++i)
    {
        if(_pirates[i].hasWoodenLeg() && _pirates[i].getAmountOfGold() < 15){
            nameOfPirates.push_back(_pirates[i].getName());
        }
    }
    return nameOfPirates;
}
int Ship::getGolds()
{
    int sum = 0;
    for (int i = 0; i < _pirates.size(); ++i) {
        sum += _pirates[i].getAmountOfGold();
    }
    return sum;
}
void Ship::lastDayOnTheShip()
{
    for (int i = 0; i < _pirates.size(); ++i) {
        _pirates[i].party();

    }

}
void Ship::prepareForBattle()
{
    for (int j = 0; j < _pirates.size(); ++j) {
        for (int i = 0; i < 5; ++i) {
            _pirates[i].work();
        }
    }
    lastDayOnTheShip();
}
