//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}
std::string Printer2D::getSize()
{
    return std::to_string(_sizeX) + "x" + std::to_string(_sizeY);
}