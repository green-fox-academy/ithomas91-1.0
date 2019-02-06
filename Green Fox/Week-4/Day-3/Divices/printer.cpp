//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "printer.h"

std::string Printer::print()
{
    std::cout << "I'm printing something that's" << getSize() << "c m." << std::endl;
}