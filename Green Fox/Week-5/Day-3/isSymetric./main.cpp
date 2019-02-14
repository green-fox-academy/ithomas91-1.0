#include <iostream>
#include <vector>

bool isSymmetric(std::vector<std::vector<int>> inputMatrix)
{
    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix[i].size(); ++j) {
            if (inputMatrix[i][j] != inputMatrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> matrix1 = {{1, 0, 1},
                                             {0, 2, 2},
                                             {1, 2, 5}};
    if (isSymmetric(matrix1)) {
        std::cout << "The matrix is symmetric" << std::endl;
    } else {
        std::cout << "The matrix is not symmetric" << std::endl;
    }

    std::vector<std::vector<int>> matrix2 = {{7, 7, 7},
                                             {6, 5, 7},
                                             {1, 2, 1}};
    if (isSymmetric(matrix2)) {
        std::cout << "The matrix is symmetric" << std::endl;
    } else {
        std::cout << "The matrix is not symmetric" << std::endl;
    }

    return 0;
}

