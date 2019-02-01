#include <iostream>

int main() {


    int tomi = 27;
    int *tage = &tomi;

    std::cout << tomi <<std::endl;
    std::cout << &tomi <<std::endl;
    std::cout << tage<<std::endl;
    std::cout << *tage<<std::endl;


    return 0;
}