#include <iostream>
#include <vector>

int hammingDistance(std::string input1, std::string input2)
{
    int hDcounter = 0;
    for (int i = 0; i < input1.size(); ++i) {
        if (input1[i] != input2[i]) {
            hDcounter++;
        }
    }
    return hDcounter;
}

std::vector<std::string> compareFunction(std::string inputString, std::vector<std::string> inputVector)
{
    std::vector<std::string> result;

    for (int i = 0; i < inputString.size(); ++i) {
        std::string vectorString = inputVector[i];

        int distance = hammingDistance(inputString, vectorString);

        if (distance <= 3) {
            result.push_back(vectorString);
        }
    }
    return result;
}

void runFirstTest()
{
    // Arrange
    std::string testInput = "apple";
    std::vector<std::string> testWordList = {"apple", "apply", "tuple", "alter"};

    // Act
    std::vector<std::string> result2 = compareFunction(testInput, testWordList);

    // Assert
    std::vector<std::string> expectedResult = {"apple", "apply", "tuple"};
    if (result2 == expectedResult) {
        std::cout << "First test passed" << std::endl;
    } else {
        std::cout << "First test failed" << std::endl;
    }

}

int main()
{
    runFirstTest();
    return 0;
}