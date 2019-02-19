#include <iostream>
#include "dish.h"
#include <map>

int main()
{

    std::string soups = "fishsoup";
    std::map<std::string, int> ingidients;
    ingidients["fish"] = 2;

    Dish soup("fishsoup", ingidients);

    return 0;
}