#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *a_p;
    int *b_p;

    a_p = &a;
    b_p = &b;

    int sum = *a_p + *b_p;

    std::cout<< sum <<std::endl;



    return 0;
}