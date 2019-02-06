//
// Created by Tamas Nemeth on 2019-02-06.
//
#include <iostream>
#include "cohort.h"

Cohort::Cohort(std::string name)
{
    _cohortName = name;
}
void Cohort::addStudent(Student * _student)
{
    students.push_back(_student);
}
void Cohort::addMentor(Mentor * _mentor)
{
    mentors.push_back(_mentor);
}
void Cohort::info()
{
    std::cout << "The " << _cohortName << " cohort has" << students.size()
                        << "students and" << mentors.size() << "mentors." << std::endl;
}