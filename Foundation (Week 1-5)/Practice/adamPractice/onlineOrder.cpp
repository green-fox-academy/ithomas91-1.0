//
// Created by Tamas Nemeth on 2019-02-19.
//

#include "onlineOrder.h"
OnlineOrder::OnlineOrder(std::string address, std::vector<Dish> dishes) : Order(dishes)
{
    _address = address;
}
