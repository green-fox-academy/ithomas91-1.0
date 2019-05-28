#include <iostream>

// Create a pointer for each variable and print out the memory addresses of that variables
// Print out the values of the pointers

int main ()
{


    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *pa = &a;

    double *pb = &b;

    std::string *pname = &name;

    std::cout<< pa <<" "<< pb<< " "<< pname<<std::endl;

    return 0;
}