#include <iostream>

// Write a program that asks for a number.
// It would ask this many times to enter an integer,
// if all the integers are entered, it should print the sum and average of these
// integers like:
//
// Sum: 22, Average: 4.4


int main(int argc, char* args[]) {


    std::cout<<"Enter any Integer please! As many you want."<<std::endl;
    int array[5];

    for( int i = 0; i < sizeof(array)/sizeof(array[0]); i++){

       std::cin>> array[i];

    }
    int sum += array[i];

    std::cout<< sum<<std::endl;

    return 0;
}