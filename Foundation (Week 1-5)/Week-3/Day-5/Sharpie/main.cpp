#include <iostream>
#include "Sharpie.h"
#include <string>

int main() {

    Sharpie Object("red", 3);

    int minus;

    std::cout << "Number of the decrease is: ";
    std::cin >> minus;

    for (int i = 0; i < minus; ++i) {
        Object.Use();
    }

    std::cout << Object.getColor()  << std::endl;
    std::cout << Object.getWidth() <<
    std::endl;
    std::cout << Object.getinkAmount() << std::endl;

    return 0;
}