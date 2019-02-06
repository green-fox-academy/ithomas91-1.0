//
// Created by Tamas Nemeth on 2019-02-06.
//
#include "stringedInstrument.h"
#ifndef MODELSTRINGED_BASSGUITAR_H
#define MODELSTRINGED_BASSGUITAR_H

#include <string>


class BassGuitar : public StringedInstrument {
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    std::string sound() override;

private:
    std::string soundBass;
};


#endif //MODELSTRINGED_BASSGUITAR_H
