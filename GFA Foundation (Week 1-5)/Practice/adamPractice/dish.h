//
// Created by Tamas Nemeth on 2019-02-19.
//

#ifndef ADAMPRACTICE_DISH_H
#define ADAMPRACTICE_DISH_H

#include <string>
#include <map>
class Dish
{
 public:
  Dish(std::string name, std::map<std::string, int> ingredients);
  std::map<std::string, int> getIngridients();
 private:
  std::string _name;
  std::map<std::string, int> _ingredients;

};

#endif //ADAMPRACTICE_DISH_H
