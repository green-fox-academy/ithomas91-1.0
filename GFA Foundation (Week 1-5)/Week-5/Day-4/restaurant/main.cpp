#include <iostream>
#include <vector>
#include "employee.h"
#include "waiter.h"
#include "chef.h"
#include "manager.h"

int main()
{
    std::vector<Employee *> employees;

    Waiter waiter1("Zolko", 100);
    Chef chef1("Tomi", 500);
    Manager manager1("Niki", 1000);

    employees.push_back(&waiter1);
    employees.push_back(&chef1);
    employees.push_back(&manager1);

    for (int i = 0; i < employees.size(); ++i) {
        employees[i]->work();
        std::cout << employees[i] << std::endl;
    }
        
    return 0;
}