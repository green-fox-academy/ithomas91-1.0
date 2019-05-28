#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int add(int x);

int main() {

    std::cout << "Eneter an integer!" << std::endl;
    int x;
    std::cin >> x;
    std::cout << add(x) << std::endl;
    return 0;
}

int add(int x) {
    if (x <= 1) {
        return x;
    } else {
        return (x + add(x - 1));

    }
}