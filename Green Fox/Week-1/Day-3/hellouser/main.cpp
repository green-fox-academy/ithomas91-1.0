#include <iostream>


// Modify this program to greet user instead of the World!
// The program should ask for the name of the user


int main(int argc, char* args[]) {

    std::string typedname;

    std::cout << "What's your name?" << std::endl;

    std::cin >> typedname ;

    std::cout << "Please be welcome "<< typedname << " in my own written programme!" << std::endl;

    return 0;
}

