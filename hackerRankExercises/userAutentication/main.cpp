#include <iostream>
#include <map>
#include <fstream>
#include "functions.h"

typedef struct
{
    std::string userName;
    std::string password;
    std::map<std::string, std::string> newRegistrations;
    int numberOfNewRegistrations;
} registration_t;

int main()
{
    registration_t registration;
    std::string userAnswer;
    bool decideIfUsernameAlreadyUsed = false;
    std::cout<<"Please enter 'login' to Log In or 'register' to Register a new account!"<<std::endl;
    std::cout<<"To check database, enter database password!"<<std::endl;

    std::cin>> userAnswer;
    int boolUserAnswer = decideUserAnswer(userAnswer);

    switch (boolUserAnswer) {

        default:
            break;

        case 1:
                        std::cout << "Please enter a 'USERNAME' and a 'PASSWORD' separated by a space to REGISTER!" << std::endl;
                        std::cin >> registration.userName >> registration.password;

                        if(decideIfUsernameAlreadyUsed = checkDataBaseIfIn(registration.userName,
                                registration.password, "../database.txt")== true){
                            registerNewUser(registration.userName, registration.password, "../database.txt");
                            std::cout<<std::endl;
                            break;
                        } else {
                            break;
                        }


                        registration.newRegistrations[registration.userName] = registration.password;
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