//
// Created by Németh Tamás on 2019-02-23.
//

#ifndef DIVICESPRACTICE_COPIER_H
#define DIVICESPRACTICE_COPIER_H


#include "printer2D.h"
#include "scanner.h"

class Copier : public Printer2D, public Scanner {
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
private:
};


#endif //DIVICESPRACTICE_COPIER_H
