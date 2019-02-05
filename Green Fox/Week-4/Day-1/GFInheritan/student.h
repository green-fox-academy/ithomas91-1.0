//
// Created by Tamas Nemeth on 2019-02-05.
//

#ifndef GFINHERITAN_STUDENT_H
#define GFINHERITAN_STUDENT_H


#include "person.h"

class Student : public Person {
public:
    Student(std::string name, int age, Gender gender, std::string previousOrganisation);
    Student();
    void getGoal() override;
    void introduce() override;
    void skippedDays(int numberOfDays);


private:

    std::string previousOrganisation;
    int _skippedDays;
};


#endif //GFINHERITAN_STUDENT_H
