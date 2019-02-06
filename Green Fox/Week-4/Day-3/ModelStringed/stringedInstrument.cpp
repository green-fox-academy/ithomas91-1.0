//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "stringedInstrument.h"

void StringedInstrument::play()
{
    std::cout << _numberOfStrings << " strings " << sound() << std::endl;
}