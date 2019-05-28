//
// Created by Tamas Nemeth on 2019-02-14.
//

#include "restaurant.h"
void Restaurant::guestArrived()
{
    for (int i = 0; i < _employees.size(); ++i) {
        _employees[i]->work();
    }
}
void Restaurant::hire(Employee *employee)
{
    _employees.push_back(employee);
}
Restaurant::Restaurant(std::string name, int fundationYear, std::vector<Employee*> employee)
{
    _nameRestaurant = name;
    _fundationYear = fundationYear;
    _employees = employee;
}
