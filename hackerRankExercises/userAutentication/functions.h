#include <iostream>
#include <map>
#include <fstream>


    int decideUserAnswer(std::string answer);
    bool checkDataBaseIfIn(std::string userName, std::string password, std::string fileName);
    void login(std::string userName, std::string password);
    void registerNewUser (std::string userName, std::string password, std::string databaseFileName );
    void checkDatabase (std::string databaseFileName);
