//
// Created by Tamas Nemeth on 2019-02-11.
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <string>
class Pirate {
public:
    Pirate(std::string _pirate);
    int drinkSoumeRum(std::string _pirate);
    void howItGoingMate(std::string pirate, int _drinkSomeRum);
    //void die();
    //void brawl(x);
private:
    std::string pirate;

};

#endif //PIRATES_PIRATE_H
