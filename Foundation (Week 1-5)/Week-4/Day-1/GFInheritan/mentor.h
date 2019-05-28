//
// Created by Tamas Nemeth on 2019-02-05.
//
#include <string>
#ifndef GFINHERITAN_MENTOR_H
#define GFINHERITAN_MENTOR_H
#include "person.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};


class Mentor : public Person {
public:

Mentor(std::string name, int age, Gender gender, Level level);
Mentor();

void getGoal() override;
void introduce() override;

private:
    Level _level;

};


#endif //GFINHERITAN_MENTOR_H
