
#include <iostream>

// Create a program which accepts five integers from the console (given by the user)
// and store them in an array
// print out the memory addresses of the elements in the array

int main()
{
    int a, b, c, d, e;
    std::cout << "Enter 5 elements to the array" << std::endl;
    std::cin >> a >> b >> c >> d >> e;

    int array[] = {a, b, c, d, e};

    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << std::endl;
        std::cout << &array[i] << std::endl;
    }



    return 0;
}