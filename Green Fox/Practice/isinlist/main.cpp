#include <iostream>
#include <vector>

// Check if vector contains all of the following elements: 4,8,12,16
// Create a method that accepts vector as an input
// it should return "true" if it contains all, otherwise "false"

bool checkNums(std::vector<int>vectorToCheck, std::vector<int> numbersToCheck)
{
    int sizeOfvectorToCheck = vectorToCheck.size();
    int sizeOfnumbersToCheck = numbersToCheck.size();
    int sum = 0;

    for (int i = 0; i < sizeOfvectorToCheck; ++i) {
        for (int j = 0; j < sizeOfnumbersToCheck; ++j) {
            if (vectorToCheck[i] == numbersToCheck[j]){
                sum++;
            }
        }

    }
    if(sum == sizeOfnumbersToCheck){
        return true;
    }
    return false;
}

int main(int argc, char* args[])
{
    const std::vector<int> numbers = {2, 4, 6, 8, 10, 12, 14};
    const std::vector<int> numbers2 = {2, 4, 6, 8, 10, 12, 14, 16};
    const std::vector<int> checker = {4, 8, 12, 16};



    // Expected output: "The first vector does not contain all the numbers"
    if (checkNums(numbers, checker)) {
        std::cout << "The first vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The first vector does not contain all the numbers" << std::endl;
    }

    // Expected output: "The second vector contains all the numbers"
    if (checkNums(numbers2, checker)) {
        std::cout << "The second vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The second vector does not contain all the numbers" << std::endl;
    }

    return 0;
}