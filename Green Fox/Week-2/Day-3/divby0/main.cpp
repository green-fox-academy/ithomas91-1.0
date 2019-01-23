#include <iostream>
#include <fstream>

// Create a function that takes a number
// divides ten with it,
// and prints the result.
// It should print "fail" if the parameter is 0

int divide( int x);

int main() {

    int a;
    std::cout<< "Enter an Ineteger, please!"<<std::endl;
    std::cin>> a;
    divide(a);

    try {
        std::cout<< divide <<std::endl;
    }catch(char){
        std::cout<<"Fail!"<<std::endl;
    }


    return 0;
}

int divide ( int x){

    int y;

    if( x == 0){
        throw 'c';
    }
    y = 10/x;
    return y;

}





/*
 *
    int number1;
    double result;

    std::cout<<"Enter an Integer"<<std::endl;
    std::cin>> number1;

    try{
        if (number1 == 0){
            throw 'c';
        }
        else {
            result = 10/number1;
            std::cout<< result<<std::endl;

        }
    }catch(...) {

        std::cout<< "Fail"<<std::endl;
    }


 */