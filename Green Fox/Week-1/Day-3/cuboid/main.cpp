#include <iostream>


// Write a program that stores 3 sides of a cuboid as variables (doubles)
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000


int main(int argc, char* args[]) {

     // V:  a*b*c
     // A:  6*a*a

     int a = 4;
     int b = 6;
     int c = 10;

     int v = (a*b*c);
     int a2 = (6*a*a);

     std::cout << "Surface area: " << v << std::endl;
     std::cout << "volume: " << a2 <<std::endl;



    return 0;
}


