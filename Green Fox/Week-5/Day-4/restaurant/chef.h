//
// Created by Tamas Nemeth on 2019-02-14.
//

#ifndef RESTAURANT_CHEF_H
#define RESTAURANT_CHEF_H

#include <map>
#include "employee.h"

class Chef : public Employee
{
 public:
  Chef(std::string name, int experience);
  void work()override;
  void cook(std::string foodName);
 private:
  std::map<std::string, int> _cookedFood;

};

#endif //RESTAURANT_CHEF_H
