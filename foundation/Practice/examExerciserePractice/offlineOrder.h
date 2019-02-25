//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef EXAMEXERCISEREPRACTICE_OFFLINEORDER_H
#define EXAMEXERCISEREPRACTICE_OFFLINEORDER_H

#include "order.h"
class OfflineOrder : public Order
{
 public:
    OfflineOrder(int table, std::vector<Dish> dishes);
 private:
    int _table;
};

#endif //EXAMEXERCISEREPRACTICE_OFFLINEORDER_H
