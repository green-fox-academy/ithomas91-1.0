//
// Created by Németh Tamás on 2019-02-23.
//

#include <iostream>
#include "printer.h"

void Printer::Print()
{
    std::cout << "I'm printing something that's" << getSize() << "cm." << std::endl;
}
