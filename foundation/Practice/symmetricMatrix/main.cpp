#include <iostream>
#include <vector>

bool isSymetric(std::vector<std::vector<int>> inputMatrix) {
    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix[i].size(); ++j) {
            if (inputMatrix[i][j] != inputMatrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    std::vector<std::vector<int>> testMatrix = {{1, 0, 1},
                                                {0, 2, 2},
                                                {1, 2, 5}};

    if (isSymetric(testMatrix)){
        std::cout << "Matrix is symetric!";
    } else {
        std::cout << "Matrix is not symetric";
    }


    return 0;
}