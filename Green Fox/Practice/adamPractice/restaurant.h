//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef ADAMPRACTICE_RESTAURANT_H
#define ADAMPRACTICE_RESTAURANT_H

#include <string>
#include <map>
#include "order.h"
class Restaurant
{
 public:
  Restaurant(std::map<std::string, int> inventory);
  Order &receiveOrder(Order &order);

 private:
    std::map<std::string, int> _inventory;
};

#endif //ADAMPRACTICE_RESTAURANT_H
