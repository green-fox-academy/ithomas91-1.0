//
// Created by Tamas Nemeth on 2019-02-05.
//
#include <string>
#ifndef GFINHERITAN_PERSON_H
#define GFINHERITAN_PERSON_H

enum Gender
        {
        MALE,
        FEMALE,
        OTHER
        };

std::string getGenderString(Gender gender);

class Person {
public:
    Person(std::string name, int age, Gender gender);
    Person();
    virtual void introduce();
    virtual void getGoal();
protected:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GFINHERITAN_PERSON_H
