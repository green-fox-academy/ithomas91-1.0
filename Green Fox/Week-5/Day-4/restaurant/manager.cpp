//
// Created by Tamas Nemeth on 2019-02-14.
//

#include "manager.h"
void Manager::work()
{
    _experience++;
    haveAmeeting();
}
void Manager::haveAmeeting()
{
    moodLevel -= _experience;
}
Manager::Manager(std::string name, int experience) : Employee(name, experience)
{

}
