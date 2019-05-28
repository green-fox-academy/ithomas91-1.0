//
// Created by Tamas Nemeth on 2019-02-06.
//
#include <string>
#ifndef GFINHERITAN_SPONSOR_H
#define GFINHERITAN_SPONSOR_H


#include "person.h"

class Sponsor : public Person
        {
    public:
    Sponsor(std::string name, int age, Gender gender, std::string company);
    Sponsor();

    void introduce() override;
    void getGoal() override;
    void hire();

    private:
    std::string _company;
    int _hiredStudents;
};

#endif //GFINHERITAN_SPONSOR_H
