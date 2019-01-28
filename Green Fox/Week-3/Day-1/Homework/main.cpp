#include <iostream>
#include <map>


int main() {

    std::map<std::string, std::string> BlackCherryTree;

    BlackCherryTree["type"] = "Cherry";
    BlackCherryTree["leaf color"] = "Dark Green";
    BlackCherryTree["age"] = "5";
    BlackCherryTree["sex"] = "Unknown";

    std::map<std::string, std::string> BlackOakTree;

    BlackCherryTree["type"] = "Oak";
    BlackCherryTree["leafColor"] = "Dark Green";
    BlackCherryTree["age"] = "10";
    BlackCherryTree["sex"] = "Male";

    std::map<std::string, std::string> SilverMapleTree;

    BlackCherryTree["type"] = "Maple";
    BlackCherryTree["leaf color"] = "Pale Green";
    BlackCherryTree["age"] = "12";
    BlackCherryTree["sex"] = "Female";

    std::map<std::string, std::string> Basswood;

    BlackCherryTree["type"] = "Basswood";
    BlackCherryTree["leaf color"] = "Green";
    BlackCherryTree["age"] = "7";
    BlackCherryTree["sex"] = "Male";

    std::map<std::string, std::string> HawthornsTree;

    BlackCherryTree["type"] = "Hawthorns";
    BlackCherryTree["leaf color"] = "Green";
    BlackCherryTree["age"] = "3";
    BlackCherryTree["sex"] = "Unknown";


std::cout << BlackCherryTree["sex"] <<std::endl;

    return 0;
}