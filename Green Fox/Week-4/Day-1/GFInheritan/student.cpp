//
// Created by Tamas Nemeth on 2019-02-05.
//
#include <iostream>
#include <string>
#include "student.h"
#include "person.h"

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) :
Person(age, name, gender)

{
    _skippedDays = 0;
}

Student::Student() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." <<std::endl;
}

void Student::introduce()
{
    std::cout
    << "Hi, i am"
    << _name
    << ", a "
    << _age
    << " year old "
    << _gender
    << " from "
    << _previousOrganization << " who skipped "
    << _skippedDays
    << " days from the course already." << std::endl;
}

void Student::skippedDays(int numberOfDays)
{
    _skippedDays--;
}