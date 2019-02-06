//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "BassGuitar.h"
BassGuitar::BassGuitar(){

    _numberOfStrings = 4;
    soundBass = "Duum-duum-duum";
}
std::string BassGuitar::sound()
{
return soundBass;
}
BassGuitar::BassGuitar(int numberOfStrings) {
    _numberOfStrings = 5;
}
