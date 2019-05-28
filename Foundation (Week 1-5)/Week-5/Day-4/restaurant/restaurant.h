//
// Created by Tamas Nemeth on 2019-02-14.
//

#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H

#include <string>
#include <vector>
#include "employee.h"
class Restaurant
{
 public:
    Restaurant(std::string name, int fundationYear, std::vector<Employee*> employee);
    void guestArrived();
    void hire(Employee *employee);

 protected:
    std::string _nameRestaurant;
    int _fundationYear;
    std::vector<Employee*> _employees;

};

#endif //RESTAURANT_RESTAURANT_H
