#include <iostream>

int factorial(int num) {
    if (num <= 1) { //base case
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    std::cout << factorial(5) << std::endl;
    return 0;
}