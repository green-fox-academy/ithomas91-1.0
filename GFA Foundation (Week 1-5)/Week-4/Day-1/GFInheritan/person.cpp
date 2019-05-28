//
// Created by Tamas Nemeth on 2019-02-05.
//
#include <string>
#include "person.h"
#include <iostream>

std::string getGenderString(Gender gender)
{
    if(gender == Gender::MALE){
        return "male";
    } else if(gender == Gender::FEMALE){
        return "female";
    } else {
        return "other";
    }
}



Person::Person(std::string name, int age, Gender gender) {
    _name = name;
    _age = age;
    _gender = gender;
}

Person::Person() {

    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

void Person::introduce() {
    std::cout
    << "Hi, I am "
    << _name << " a "
    << _age << " year old, "
    << _gender << std::endl;
}
void Person ::getGoal() {
    std::cout << "My goal is: Live for the moment" << std::endl;
}