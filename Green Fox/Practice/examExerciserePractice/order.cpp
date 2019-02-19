//
// Created by Tamas Nemeth on 2019-02-19.
//

#include "order.h"
Order::Order(std::vector<Dish> dishes)
{
    _id = rand() % 9999 + 1001;
    _status = "";
    _dishes = dishes;
}
void Order::delay()
{
    _status = "Waiting";
}
void Order::deliver()
{
    _status = "Delivered";
}
void Order::reject()
{
    _status = "Rejected";
}
std::vector<Dish> Order::getDishes()
{
    return _dishes;
}
