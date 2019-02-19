//
// Created by Tamas Nemeth on 2019-02-19.
//

#include "dish.h"
Dish::Dish(std::string name, std::map<std::string, int> ingredients)
{
    _name = name;
    _ingredients = ingredients;
}
std::map<std::string, int> Dish::getIngridients()
{
    return _ingredients;
}
