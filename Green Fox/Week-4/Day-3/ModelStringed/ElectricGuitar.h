//
// Created by Tamas Nemeth on 2019-02-06.
//
#include "stringedInstrument.h"
#ifndef MODELSTRINGED_ELECTRICGUITAR_H
#define MODELSTRINGED_ELECTRICGUITAR_H


class ElectricGuitar : public StringedInstrument{
public:
    ElectricGuitar();
    ElectricGuitar(int numberOfStrings);
    std::string sound() override;

private:
    std::string soundElectric;


};


#endif //MODELSTRINGED_ELECTRICGUITAR_H
