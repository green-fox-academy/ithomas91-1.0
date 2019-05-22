#include "functions.h"

typedef struct
{
    std::string userName;
    std::string password;
    std::map<std::string, std::string> newRegistrations;
    int numberOfNewRegistrations;
} registration_t;


int decideUserAnswer(std::string answer)
{
    if(answer == "register"){
        return 1;
    } else if(answer == "login") {
        return 0;
    } else if ( answer == "databasePassword"){
        return 2;
    } else {
        std::cout<<"You have entered wrong statement, please try again!"<<std::endl;
        return -1;
    }
}

bool checkDataBaseIfIn(std::string userName, std::string password, std::string fileName)
{
    std::ifstream database;
    database.open(fileName);

    if(!database.is_open()){
        std::cout<<"File can't be opened!"<<std::endl;
    }
    bool result = false;
    std::string fileUsername;
    std::string filePassword;
    while(database >> fileUsername >> filePassword){
        if(fileUsername == userName){
            std::cout << "Username already been used, try another please!" << std::endl;
            result = false;
        } else {
            result = true;
        }
    }
    database.close();
    return result;
}


void login(std::string userName, std::string password)
{
    std::ifstream database;
    database.open("../database.txt");

    if(!database.is_open()){
        std::cout<<"File can't be opened!"<<std::endl;
    }

    std::string fileUsername;
    std::string filePassword;
    bool canLogin = true;
    while(database >> fileUsername >> filePassword) {
        if(userName == fileUsername && password == filePassword){
            std::cout << "You have logged in successfully!" << std::endl;
            break;
        } else {
            canLogin = false;
        }
    }
    if(canLogin == false) {
        std::cout << "Couldn't find the entered username in the database! Haven't registered yet? Restart the program"
                     "and enter 'register'" << std::endl;

    }
}

void registerNewUser (std::string username, std::string password, std::string databaseFileName )
{
    std::ofstream database;
    database.open(databaseFileName, std::ios::app);

    if(!database.is_open()){
        std::cout<<"File can't be opened!"<<std::endl;
    }

    registration_t registration;
    registration.userName = username;
    registration.password = password;

    database << username <<" "<< password<<std::endl;

    database.close();

}

void checkDatabase (std::string databaseFileName)
{
    std::ifstream database;
    database.open(databaseFileName);

    if(!database.is_open()){
        std::cout<<"File can't be opened!"<<std::endl;
    }
    std::string fileUsername;
    std::string filePassword;
    registration_t alreadyRegisteredUsers;
    while(database >> fileUsername >> filePassword){
        alreadyRegisteredUsers.newRegistrations[fileUsername] = filePassword;
    }

    for (std::map<std::string, std::string>::iterator it=alreadyRegisteredUsers.newRegistrations.begin();
         it!=alreadyRegisteredUsers.newRegistrations.end(); ++it) {
        std::cout << it->first << " - " << it->second << '\n';
    }

    database.close();
}
