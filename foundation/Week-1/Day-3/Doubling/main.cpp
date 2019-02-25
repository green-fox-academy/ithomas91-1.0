#include <iostream>
#include <string>


int doubling ( int );


int main(int argc, char* args[]) {

    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    int basenum = 123;



    int returnvalue =  doubling(basenum);


    std::cout<< "Doubling baseNum: " << returnvalue << std::endl;


    return 0;
}

int doubling (int input ) {

    return input * 2;

}