#include <iostream>
#include <vector>

std::vector<int> newVector(std::vector<int> inputVector, int inputNumber)
{
    std::vector<int> returnVector = inputVector;
    int maxValue = returnVector[0];

    for (int i = 1; i < returnVector.size(); ++i) {
        if (maxValue < returnVector[i]) {
            maxValue = returnVector[i];
        }
    }
    for (int j = inputNumber - 1; j < returnVector.size(); j += inputNumber) {
        returnVector[j] *= maxValue;
    }
    return returnVector;
}

int main()
{

    std::vector<int> test{1, 2, 3, 8, 5};
    int n = 4;
    std::vector<int> newTest = newVector(test, n);
    for (int i = 0; i < newTest.size(); ++i) {
        std::cout << newTest[i] << " ";
    }
    return 0;
}