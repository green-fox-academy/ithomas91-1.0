//
// Created by Tamas Nemeth on 2019-02-06.
//

#include <iostream>
#include "scanner.h"
Scanner::Scanner(int speed) {
    _speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document " << _speed << " ppm" <<std::endl;
}