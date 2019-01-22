#include <iostream>

// Change the value of the variable called 'temperature' using a pointer
// (you have to create the pointer first)


int main ()
{


    float temperature = 21.3;
    float temperature2 = 32.2;

    float *temperaturep;
    float *temperaturep2;



    temperaturep = &temperature;
    temperaturep2 = &temperature2;


    *temperaturep = *temperaturep2;



    std::cout<< *temperaturep<<std::endl;
    return 0;
}