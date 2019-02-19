//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef EXAMEXERCISEREPRACTICE_DISH_H
#define EXAMEXERCISEREPRACTICE_DISH_H

#include <string>
#include <map>
class Dish
{
 public:
  Dish(std::string name, std::map<std::string, int> ingredients);
  std::map<std::string, int> getIngredients();
 private:
    std::string _name;
    std::map<std::string, int> _ingredients;
};

#endif //EXAMEXERCISEREPRACTICE_DISH_H
