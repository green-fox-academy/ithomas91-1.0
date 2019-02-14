//
// Created by Tamas Nemeth on 2019-02-14.
//

#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include "employee.h"

class Manager : public Employee
{
 public:
  Manager(std::string name, int experience);
  void work()override;
  void haveAmeeting();
 private:
    int moodLevel = 400;
};

#endif //RESTAURANT_MANAGER_H
