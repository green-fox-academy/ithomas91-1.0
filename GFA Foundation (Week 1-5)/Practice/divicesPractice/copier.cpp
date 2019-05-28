//
// Created by Németh Tamás on 2019-02-23.
//

#include <iostream>
#include "copier.h"

Copier::Copier(int sizeX, int sizeY, int speed): Printer2D(sizeX, sizeY), Scanner(speed) {
    _sizeX = sizeX;
    _sizeY = sizeY;
    _speed = speed;
}

void Copier::copy() {
    Scan();
    std::cout << "and" << std::endl;
    Print();
}
