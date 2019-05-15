#include <iostream>

void staircase(int n){

    int temp = n;
    int x = temp + 1;
    while (temp > 0) {
        for (int i = 1; i < x; ++i) {
            if (i >= temp) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        temp--;
    }
    std::cout << std::endl;

}


int main() {

    int stairHeight;

    std::cout<< "Please enter an integer to get a height of the Staircase!"<<std::endl;
    std::cin >> stairHeight;

    staircase(stairHeight);

    std::cout<< "There you go, enjoy your "<< stairHeight << " # tall Staircase!"<<std::endl;

    return 0;
}