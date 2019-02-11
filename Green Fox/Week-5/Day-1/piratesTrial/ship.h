//
// Created by Tamas Nemeth on 2019-02-11.
//

#ifndef PIRATESTRIAL_SHIP_H
#define PIRATESTRIAL_SHIP_H

#include <vector>
#include "pirate.h"

class Ship {
public:
    void addPirate(Pirate);
    std::vector<std::string>getPoorPirates();
    int getGolds();
    void lastDayOnTheShip();
    void prepareForBattle();
private:
    std::vector<Pirate> _pirates;
   // std::vector<Pirate*> _pirates;
};

#endif //PIRATESTRIAL_SHIP_H
