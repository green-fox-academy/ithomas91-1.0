#include <iostream>
#include <vector>

// Create a function named `rotateMatrix` that takes an n×n integer matrix (vector of vectors) as parameter
// and returns a matrix which elements are rotated 90 degrees clockwise.
//
// example input:
// [[1, 2, 3],
// [4, 5, 6],
// [7, 8, 9]]

std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> inputMatrix) {
    std::vector<std::vector<int>> tempVector = inputMatrix;
    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix[i].size(); ++j) {
            tempVector[i][j] = inputMatrix[j][i];
        }
    }

    std::vector<std::vector<int>> result = tempVector;
    for (int k = 0; k < inputMatrix.size(); ++k) {
        for (int i = 0; i < inputMatrix[i].size(); ++i) {
            result[k][i] = tempVector[k][inputMatrix.size() - i - 1];
        }
    }
    return result;
}

int main() {


    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}};

    std::vector<std::vector<int>> rotatedMatrix = rotateMatrix(matrix);
    for (int i = 0; i < rotatedMatrix.size(); ++i) {
        for (int j = 0; j < rotatedMatrix[i].size(); ++j) {
            std::cout << rotatedMatrix[i][j] << " ";
        }
        std::cout <<std::endl;
    }

    return 0;
}