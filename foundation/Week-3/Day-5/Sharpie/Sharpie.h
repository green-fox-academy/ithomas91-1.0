//
// Created by Tamas Nemeth on 2019-02-01.
//
#include <string>
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {
public:
    Sharpie(std::string _color, float _width);
    void Use();

    std::string getColor();
    float getWidth();
    float getinkAmount();


private:

    std::string color;
    float width;
    float inkAmount;

};


#endif //SHARPIE_SHARPIE_H
