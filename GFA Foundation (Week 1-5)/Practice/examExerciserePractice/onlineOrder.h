//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef EXAMEXERCISEREPRACTICE_ONLINEORDER_H
#define EXAMEXERCISEREPRACTICE_ONLINEORDER_H

#include "order.h"
class OnlineOrder : public Order
{
 public:
  OnlineOrder(std::string address, std::vector<Dish> dishes);
 private:
    std::string _address;
};

#endif //EXAMEXERCISEREPRACTICE_ONLINEORDER_H
