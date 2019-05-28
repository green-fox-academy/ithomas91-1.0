//
// Created by Tamas Nemeth on 2019-02-14.
//

#ifndef RESTAURANT_WAITER_H
#define RESTAURANT_WAITER_H

#include "employee.h"
class Waiter : public Employee
{
 public:
  Waiter(std::string name, int experience);
  void work()override;

 private:
  int _tips;
};

#endif //RESTAURANT_WAITER_H
