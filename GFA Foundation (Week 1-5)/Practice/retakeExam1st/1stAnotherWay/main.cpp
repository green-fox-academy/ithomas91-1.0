#include <iostream>
#include <vector>
#include <MacTypes.h>

std::vector<std::string> filterVector(std::string stringInput, std::vector<std::string> vectorInput)
{
    std::vector<std::string> result;

    for (int i = 0; i < vectorInput.size(); ++i) {
        std::string vectorString = vectorInput[i];
        int distanceCounter = 0;

        for (int j = 0; j < stringInput.size(); ++j) {
            if (vectorString[i] != stringInput[j]) {
                distanceCounter++;
            }
        }
        if (distanceCounter <= 3) {
            result.push_back(vectorString);
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> testVector = {"apple", "apply", "tuple", "alter"};
    std::string testS = "apple";

    std::vector<std::string> finalResult = filterVector(testS, testVector);
    for (int i = 0; i < finalResult.size(); ++i) {
        std::cout << finalResult[i] << " ";
    }
    return 0;
}