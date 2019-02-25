//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef ADAMPRACTICE_ORDER_H
#define ADAMPRACTICE_ORDER_H

#include <string>
#include <vector>
#include "dish.h"
class Order
{
 public:
  Order(std::vector<Dish> dishes);
  void delay();
  void deliver();
  void reject();
  std::vector<Dish> getDishes();

 protected:
    int _id;
    std::string _status;
    std::vector<Dish> _dishes;
};

#endif //ADAMPRACTICE_ORDER_H
