#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

int resfunc(int x);

int main() {

    int x;

    std::cout << "Enter an integer" << std::endl;
    std::cin >> x;
    std::cout << resfunc(x) << std::endl;

    return 0;
}

int resfunc(int x) {
    if(x == 0) {
        return 0;
    }else {
        std::cout << x << std::endl;
        return resfunc(x - 1);
    }
}
