//
// Created by Tamas Nemeth on 2019-02-06.
//
#include <iostream>
#include <string>
#include "sponsor.h"


Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) :
Person(name, age, gender)
{}

Sponsor::Sponsor()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
    _company = "Google";
    _hiredStudents = 0;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << _name << " , a " << _age << " year old "
              <<  "who represents" << _company << " and hired "
              << _hiredStudents << " students so far." << std::endl;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;

}

void Sponsor::hire()
{
    _hiredStudents--;
}

