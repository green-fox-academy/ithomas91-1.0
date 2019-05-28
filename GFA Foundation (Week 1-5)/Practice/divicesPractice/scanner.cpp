//
// Created by Németh Tamás on 2019-02-23.
//

#include <iostream>
#include "scanner.h"

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::Scan()
{
    std::cout << "I'm scanning a document " << _speed << "ppm" << std::endl;
}
