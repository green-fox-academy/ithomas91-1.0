#include <iostream>
#include <vector>

std::vector<int> newVector(std::vector<int> inputVector, int inputNumber)
{
    int maxValue = 0;
    for (int i = 0; i < inputVector.size(); ++i) {
        if(inputVector[i] > maxValue){
            maxValue = inputVector[i];
        }
    }
    for (int i = 0; i < inputVector.size(); ++i) {
        if ((i + 1) % inputNumber == 0) {
            inputVector[i] *= maxValue;
        }
    }

    return inputVector;
}

int main() {

    std::vector<int> testVector = {1, 2, 3, 4, 5, 6};

    std::vector<int> test = newVector(testVector, 3);
    for (int i = 0; i < test.size(); ++i) {
        std::cout << test[i] << " ";
    }

    return 0;
}