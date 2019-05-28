//
// Created by Tamas Nemeth on 2019-02-06.
//

#ifndef DIVICES_PRINTER_H
#define DIVICES_PRINTER_H
#include <string>
#include <iostream>

class Printer {
public:
virtual std::string getSize() = 0;
void print();
};

#endif //DIVICES_PRINTER_H
