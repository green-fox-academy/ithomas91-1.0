//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef ADAMPRACTICE_OFFLINEORDER_H
#define ADAMPRACTICE_OFFLINEORDER_H

#include "order.h"
class OfflineOrder : public Order
{
 public:
    OfflineOrder(int table, std::vector<Dish> dishes);
 private:
    int _table;
};

#endif //ADAMPRACTICE_OFFLINEORDER_H
