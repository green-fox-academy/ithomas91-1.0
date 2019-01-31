#include <iostream>

int main() {

int length = 1;
int rows = 20;

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < length; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
        length++;
    }

    return 0;
}