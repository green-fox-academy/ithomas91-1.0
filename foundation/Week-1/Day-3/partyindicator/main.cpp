#include <iostream>

// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys
// It should print: The party is excellent!
// If the the number of girls and boys are equal and 20 or more people are coming to the party
//
// It should print: Quite cool party!
// If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
//
// It should print: Average party...
// If there are less people coming than 20
//
// It should print: Sausage party
// If no girls are coming, regardless the count of the people


int main(int argc, char* args[]) {

    int girl;
    int boy;

    std::cout << "Who came to the party?"<<std::endl;

    std::cin >> girl >> boy;

    std::cout<< girl << " girls and "<< boy << " boys came to the party."<< std::endl;

    if((girl + boy > 20)  and (girl == boy)) {

        std::cout << "The party is excellent!!!" << std::endl;
    }

    else if((girl + boy > 20)  and (girl != boy)){

            std::cout << "Quiet good party!" << std::endl;
        }

    else if(girl + boy < 20){

        std::cout << "Avarage party!"<<std::endl;
    }

    if (girl == 0){

        std::cout<<"Sausage party!"<<std::endl;
    }
    return 0;
}
