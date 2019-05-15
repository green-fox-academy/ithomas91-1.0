#include <iostream>
#include <map>
#include <fstream>

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

void checkDataBaseIfIn(std::string userName, std::string password, std::string fileName)
{
    std::ifstream database;
    database.open(fileName);

    if(!database.is_open()){
        std::cout<<"File can't be opened!"<<std::endl;
    }

    std::string fileUsername;
    std::string filePassword;
    while(database >> fileUsername >> filePassword){
        if(fileUsername == userName){
            std::cout << "Username already been used, try another please!" << std::endl;
        }
    }
    database.close();

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

int main()
{

    registration_t registration;
    std::string userAnswer;
    std::cout<<"Please enter 'login' to Log In or 'register' to Register a new account!"<<std::endl;
    std::cout<<"To check database, enter database password!"<<std::endl;

    std::cin>> userAnswer;
    int boolUserAnswer = decideUserAnswer(userAnswer);

    switch (boolUserAnswer) {

        default:
            break;

        case 1:

                std::cout << "Please enter a number of the new registrations!" << std::endl;

                std::cin >> registration.numberOfNewRegistrations;
                    for (int i = 0; i < registration.numberOfNewRegistrations; ++i) {
                        std::cout << "Please enter a 'USERNAME' and a 'PASSWORD' separated by a space to REGISTER!" << std::endl;
                        std::cin >> registration.userName >> registration.password;

                        checkDataBaseIfIn(registration.userName, registration.password, "../database.txt");

                        std::cout<<std::endl;

                        registration.newRegistrations[registration.userName] = registration.password;
                    }
                    break;


        case 0:

                std::cout << "Please enter a 'USERNAME' and a 'PASSWORD' separated by a space to LOGIN" << std::endl;

                std::cin >> registration.userName >> registration.password;

                login(registration.userName, registration.password);

                std::cout<<std::endl;

                break;

        case 2 :

            checkDatabase("../database.txt");

                break;

        case -1 :
            break;
    }



    for (std::map<std::string, std::string>::iterator it=registration.newRegistrations.begin();
    it!=registration.newRegistrations.end(); ++it) {
        std::cout << it->first << " - " << it->second << '\n';
    }


    return 0;
}