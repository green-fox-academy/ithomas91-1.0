#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> inputVector)
{
    std::vector<int> tempVector[inputVector.size()];
    for (int i = 0; i < inputVector.size()-1; ++i) {
        for (int j = 0; j < inputVector.size()-i-1; ++j) {
            if(inputVector[j] > inputVector[j+1]){
                tempVector += inputVector[j];
            }
        }
    }
    return tempVector;
}

int main(int argc, char* args[])
{
    std::vector<int> numbers = {1, 11, 34, 52, 61};

    return 0;
}