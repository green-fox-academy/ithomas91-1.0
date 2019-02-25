//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef EXAMEXERCISEREPRACTICE_RESTAURANT_H
#define EXAMEXERCISEREPRACTICE_RESTAURANT_H

#include <string>
#include <vector>
#include "order.h"
class Restaurant
{
 public:
    Restaurant(std::vector<std::string, int> inventory);
    Order receiveOrder(Order order);
 private:
  std::vector<std::string, int> _inventory;
};

#endif //EXAMEXERCISEREPRACTICE_RESTAURANT_H
