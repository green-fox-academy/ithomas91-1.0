//
// Created by Tamas Nemeth on 2019-02-06.
//
#include <string>
#include <istream>
#include <vector>
#include "student.h"
#include "mentor.h"

#ifndef GFINHERITAN_COHORT_H
#define GFINHERITAN_COHORT_H


class Cohort : public Student, Mentor {
public:
    Cohort(std::string cohortName);
    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();

private:
    std::string _cohortName;
    std::vector<Student*> students;
    std::vector<Mentor*> mentors;

};


#endif //GFINHERITAN_COHORT_H
