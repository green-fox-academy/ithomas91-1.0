//
// Created by Tamas Nemeth on 2019-02-19.
//

#include "restaurant.h"
Restaurant::Restaurant(std::vector<std::string, int> inventory)
{
    _inventory = inventory;
}
Order Restaurant::receiveOrder(Order order)
{
    return order;
}
