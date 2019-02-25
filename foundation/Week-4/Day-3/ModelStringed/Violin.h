//
// Created by Tamas Nemeth on 2019-02-06.
//
#include "stringedInstrument.h"
#ifndef MODELSTRINGED_VIOLIN_H
#define MODELSTRINGED_VIOLIN_H


class Violin : public StringedInstrument {
public:
    Violin();
    std::string sound() override;

private:
    std::string soundViolin;
};


#endif //MODELSTRINGED_VIOLIN_H
