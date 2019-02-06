//
// Created by Tamas Nemeth on 2019-02-06.
//
#ifndef MODELSTRINGED_STRINGEDINSTRUMENT_H
#define MODELSTRINGED_STRINGEDINSTRUMENT_H
#include "instrument.h"

class StringedInstrument : public Instrument{
public:
    virtual std::string sound() = 0;
    void play() override;
protected:
    int _numberOfStrings;

};

#endif //MODELSTRINGED_STRINGEDINSTRUMENT_H
