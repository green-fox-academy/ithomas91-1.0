#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

int func(int x);

int main() {
    std::cout << "Enter a non-integer!" << std::endl;

    int x;
    std::cin >> x;
    func(x);
    std::cout << func(x) << std::endl;

    return 0;
}

int func(int x) {
    if (x < 10) {
        return x;

    } else {
        return func(x / 10) + func(x % 10);

    }
}
