#include <iostream>

int main(int argc, char const *argv[])
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87


        int age = 27;
        int height = 2;

    std::cout << "My name is Tamas" << std::endl;
    std::cout << "I'm " << age << " years old." << std::endl;
    std::cout << "I'm " << height << "m tall." << std::endl;


    return 0;
}