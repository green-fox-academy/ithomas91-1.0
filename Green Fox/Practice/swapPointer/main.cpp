#include <iostream>

// Create a function which swaps the values of 'a' and 'b'
// This time use a void funtion and pointers

void swap(int &_a, int &_b)
{
    int tempC = 0;

    tempC = _a;
    _a = _b;
    _b = tempC;

    std::cout << _a << " " << _b;
}

int main ()
{


    int a = 10;
    int b = 316;

    int *pA = &a;
    int *pB = &b;

    swap(a, b);

    return 0;
}