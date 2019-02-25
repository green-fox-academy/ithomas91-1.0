#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int func(int x, int y);

int main() {

        int xbunny;
        int xear;

        std::cout << " Enter the numbers of bunnis, please!" << std::endl;
        std::cin >> ybunny;


        std::cout << "The total number of the ears is: " << xear << std::endl;

    return 0;
}

int func(int x, int y) {
    if (x >= 0) {
        return 0;
    }else {
     return 2 * func(x - 1)
    }
}
