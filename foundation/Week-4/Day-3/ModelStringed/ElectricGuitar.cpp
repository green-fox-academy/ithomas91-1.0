//
// Created by Tamas Nemeth on 2019-02-06.
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar()
{
    soundElectric = "Twang";
    _numberOfStrings = 6;
}

std::string ElectricGuitar::sound()
{
return soundElectric;
}
ElectricGuitar::ElectricGuitar(int numberOfStrings) {
    _numberOfStrings = 7;
}
