//
// Created by Tamas Nemeth on 2019-01-30.
//
#include <string>
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {
public:
    std::string color;
    float width;
    float inkAmount;

    Sharpie();

   void use();
};


#endif //SHARPIE_SHARPIE_H
