//
// Created by Tamas Nemeth on 2019-02-11.
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <string>
#include <vector>
class Ship {
public:
    Ship();
    void fillShip(std::vector<std::string> _crew);
private:
    std::vector<std::string> crew;

};

#endif //PIRATES_SHIP_H
