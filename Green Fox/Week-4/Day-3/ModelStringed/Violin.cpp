//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "Violin.h"

Violin::Violin()
{
    soundViolin = "Screech";
    _numberOfStrings = 4;
}

std::string Violin::sound()
{
return soundViolin;
}