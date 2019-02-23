//
// Created by Németh Tamás on 2019-02-23.
//

#include "printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

std::string Printer2D::getSize() {
    return std::to_string(_sizeX) + " X " + std::to_string(_sizeY);
}
