#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the integer part of 22 divided by 13

    // Print the reminder of 22 divided by 13


    int a = 22;
    int b = 13;

     int result1 = a + b;
        std::cout << result1 <<std::endl;

        int result2 = a - b;
        std::cout << result2 <<std::endl;

        int result3 = a * b;
        std::cout << result3 <<std::endl;

        int result4 = a % b;
        std::cout << result4 <<std::endl;

        std::cout << 22. / 13 <<std::endl;

    std::cout << 22 / 13. <<std::endl;

    std::cout << 22. / 13. <<std::endl;

    int result6 = 22 % 13;
    std::cout << result6 <<std::endl;













    return 0;
}