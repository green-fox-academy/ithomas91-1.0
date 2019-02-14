//
// Created by Tamas Nemeth on 2019-02-14.
//

#include "chef.h"
Chef::Chef(std::string name, int experience) : Employee(name, experience)
{

}
void Chef::work()
{
    _experience++;
}
void Chef::cook(std::string foodName)
{
    _cookedFood[foodName]++;
}
