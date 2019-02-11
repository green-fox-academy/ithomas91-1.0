//
// Created by Tamas Nemeth on 2019-02-11.
//

#ifndef PIRATESTRIAL_PIRATE_H
#define PIRATESTRIAL_PIRATE_H

#include <string>
class Pirate {
public:
    Pirate(std::string name, bool isCaptain, bool hasWoodenLeg);
    void work();
    void party();
    std::string toString();

    int getAmountOfGold();
    std::string getName();
    bool hasWoodenLeg();
    bool isCaptain();

private:
    std::string _name;
    int _amountOfGold;
    int _healthPoint;
    bool _isCaptain;
    bool _hasWoodenLeg;

};

#endif //PIRATESTRIAL_PIRATE_H
