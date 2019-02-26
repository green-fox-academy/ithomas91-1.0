#include <iostream>
#include <vector>

int getCharacterPairs(std::vector<char> firstInput, std::vector<char> secondInput)
{
    int pairCounter = 0;
    for (int i = 0; i < firstInput.size(); ++i) {
        for (int j = 0; j < secondInput.size(); ++j) {
            if(firstInput[i] == secondInput[j]){
                pairCounter++;
            }
        }
    }
    return pairCounter;
}

int main()
{
    // Arrange
    std::vector<char> testArr = {'a', 'b', 'c'};
    std::vector<char> testArr2 = {'c', 'b', 'd', 'e'};

    // Act
    int result = getCharacterPairs(testArr, testArr2);

    // Assert
    if (result == 2) {
        std::cout << "First test passed" << std::endl;
    } else {
        std::cout << "First test failed" << std::endl;
    }

    // Arrange
    std::vector<char> testArr3 = {'e', 'j', 'k', 'l'};
    std::vector<char> testArr4 = {'x', 'k', '*', '/', '-', 'l'};

    // Act
    int result1 = getCharacterPairs(testArr3, testArr4);

    // Assert
    if (result1 == 2) {
        std::cout << "Second test passed" << std::endl;
    } else {
        std::cout << "Second test failed" << std::endl;
    }

    return 0;
}