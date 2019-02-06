//
// Created by Tamas Nemeth on 2019-02-06.
//

#ifndef DIVICES_PRINTER3D_H
#define DIVICES_PRINTER3D_H
#include "printer.h"

class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;

private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;

};

#endif //DIVICES_PRINTER3D_H
