//
// Created by Németh Tamás on 2019-02-23.
//

#ifndef DIVICESPRACTICE_PRINTER2D_H
#define DIVICESPRACTICE_PRINTER2D_H


#include <string>
#include "printer.h"

class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
};


#endif //DIVICESPRACTICE_PRINTER2D_H
