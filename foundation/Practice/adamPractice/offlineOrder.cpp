//
// Created by Tamas Nemeth on 2019-02-19.
//

#include "offlineOrder.h"
OfflineOrder::OfflineOrder(int table, std::vector<Dish> dishes) : Order(dishes)
{
    _table = table;
}
