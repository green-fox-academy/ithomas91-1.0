//
// Created by Tamas Nemeth on 2019-02-14.
//

#ifndef RESTAURANT_EMPLOYEE_H
#define RESTAURANT_EMPLOYEE_H
#include <string>

class Employee
{
 public:
  Employee(std::string nameEmployee, int experience = 0);
  virtual void work() = 0;

 protected:
    std::string _nameEmployee;
    int _experience;

};

#endif //RESTAURANT_EMPLOYEE_H
