//
// Created by Tamas Nemeth on 2019-02-06.
//

#ifndef DIVICES_COPIER_H
#define DIVICES_COPIER_H

#include "scanner.h"
#include "printer2D.h"
class Copier : public Scanner, public Printer2D
{
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
};

#endif //DIVICES_COPIER_H
