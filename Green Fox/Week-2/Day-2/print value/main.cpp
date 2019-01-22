#include <iostream>

// Print out the value of the variable called 'age' using a pointer
    // (you have to create the pointer first)

int main ()
{


    int age = 31;

    int *agep;

    agep = &age;

    std::cout<< *agep<<std::endl;


    return 0;
}