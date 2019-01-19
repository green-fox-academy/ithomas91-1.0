#include <iostream>



// Write a program that reads a number from the standard input, then draws a
// triangle like this:
//
// *
// **
// ***
// ****
//
// The triangle should have as many lines as the number was



int main(int argc, char* args[]) {


    int request;    // Request lines from UserInput.

    std::cout << "How many lines do you want?"<< std::endl;

    std::cin >> request;

    for(int i = request; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }


    return 0;
}