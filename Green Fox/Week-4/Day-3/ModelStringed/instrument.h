//
// Created by Tamas Nemeth on 2019-02-06.
//
#include <string>
#include <iostream>
#ifndef MODELSTRINGED_INSTRUMENT_H
#define MODELSTRINGED_INSTRUMENT_H


class Instrument{
public:
    virtual void play() = 0;

protected:
    std::string name;

};

#endif //MODELSTRINGED_INSTRUMENT_H
