
#include <iostream>

// Change the value of the variable called 'temperature' using a pointer
// (you have to create the pointer first)

int main ()
{
    float newTemperature = 31.5;
    float *ptemperature = &newTemperature;

    float temperature = 21.3;

    std::cout << *ptemperature << std::endl;

    return 0;
}