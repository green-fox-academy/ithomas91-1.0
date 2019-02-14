//
// Created by Tamas Nemeth on 2019-02-14.
//

#include "waiter.h"
void Waiter::work()
{
    _tips++;
    _experience ++;
}
Waiter::Waiter(std::string name, int experience) : Employee(name, experience)
{

}
