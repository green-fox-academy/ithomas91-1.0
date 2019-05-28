//
// Created by Tamas Nemeth on 2019-02-06.
//

#ifndef DIVICES_PRINTER2D_H
#define DIVICES_PRINTER2D_H
#include "printer.h"


class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;

protected:
int _sizeX;
int _sizeY;
};

#endif //DIVICES_PRINTER2D_H
