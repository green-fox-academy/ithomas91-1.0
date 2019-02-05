//
// Created by Tamas Nemeth on 2019-02-01.
//
#include <string>
#include "Sharpie.h"

Sharpie::Sharpie(std::string _color, float _width)
{
    color = _color;
    width = _width;
    inkAmount = 100;
}

void Sharpie::Use()
{
    inkAmount --;
}
std::string Sharpie::getColor()
{
    return color;
}

float Sharpie::getWidth()
{
    return width;
}

float Sharpie::getinkAmount()
{
    return inkAmount;
}