#include <iostream>
#include <vector>


std::vector<std::vector<int>> mirrorMatrix(std::vector<std::vector<int>> inputMatrix) {

    std::vector<std::vector<int>> tempMatrix = inputMatrix;

    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix[i].size(); ++j) {
            tempMatrix[tempMatrix.size() - 3][j] = inputMatrix[i][j];
            tempMatrix[tempMatrix.size() - 1][j] = inputMatrix[inputMatrix.size() - 3][j];
        }
    }
    return tempMatrix;
}

int main() {


    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                         {7, 8, 9}};

    std::vector<std::vector<int>> finalResult = mirrorMatrix(matrix);
    for (int i = 0; i < finalResult.size(); ++i) {
        for (int j = 0; j < finalResult[i].size(); ++j) {
            std::cout << finalResult[i][j] << " ";
        }
        std::cout << std::endl;
    }


    bool testFinalResult = (finalResult == std::vector<std::vector<int>>{{1, 2, 3},{4, 5, 6},{7, 8, 9}});
    std::cout << "Test case result: " << testFinalResult << std::endl;

    bool testFinalResult2 = (finalResult == std::vector<std::vector<int>>{{7, 8, 9},{4, 5, 6},{1, 2, 3}});
    std::cout << "Test case result: " << testFinalResult2 << std::endl;
return 0;
}