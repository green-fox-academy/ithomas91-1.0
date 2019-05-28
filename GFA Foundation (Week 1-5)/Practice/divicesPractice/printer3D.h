//
// Created by Németh Tamás on 2019-02-23.
//

#ifndef DIVICESPRACTICE_PRINTER3D_H
#define DIVICESPRACTICE_PRINTER3D_H


#include <string>
#include "printer.h"

class Printer3D : public Printer  {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize()override;
private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};


#endif //DIVICESPRACTICE_PRINTER3D_H
