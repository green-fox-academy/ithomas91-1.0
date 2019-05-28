#include <iostream>

// Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array


int main()
{

    std::cout<< "Enter 5 integer"<<std::endl;

    int a;
    int b;
    int c;
    int d;
    int e;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;

    int array[ ] = {a, b, c, d, e};

    int *arrayp = array;

    std::cout << "Memory adress of the array is: "<< arrayp <<std::endl;



    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        std::cout << array + i << std::endl;
    }



    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        std::cout << array[i] << std::endl;
    }


    return 0;
}