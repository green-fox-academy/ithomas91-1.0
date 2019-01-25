#include <iostream>

// Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again


int main()
{

    std::cout<<"Enter 5 integer!"<<std::endl;

    int array[5];
    
    for(int i = 0; i < sizeof(array)/ sizeof(array[0]); i++) {  // can be i < 5 , as it written

        std::cin>> array[i];
    }
    /* int a;
    int b;
    int c;
    int d;
    int e;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;

    int array[] = {a, b, c, d, e};
    */

    int *arrayp = array;

    for(int i = 0; i < sizeof(array)/sizeof(array[i]); i++){
        std::cout<< arrayp[i]<<std::endl;

    }
    return 0;
}