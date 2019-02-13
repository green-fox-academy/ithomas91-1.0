#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> matrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
    std::vector<std::vector<int>> matrix3(matrix1.size(), std::vector<int>(matrix1.size()));

    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[i].size(); ++j) {
            if (matrix1[i][j] >= matrix2[i][j]) {
                matrix3[i][j] = matrix1[i][j];
            } else if (matrix1[i][j] < matrix2[i][j]) {
                matrix3[i][j] = matrix2[i][j];

            }
        }
    }
    return matrix3;
}

int main()
{
    std::vector<std::vector<int>> myMatrix1 = {{1, 2, 3},
                                               {4, 5, 6},
                                               {7, 8, 9}};

    std::vector<std::vector<int>> myMatrix2 = {{3, 2, 5},
                                               {4, 6, 1},
                                               {9, 4, 1}};


    std::vector<std::vector<int>> myMatrix3 = matrix(myMatrix1, myMatrix2);
    for (int i = 0; i < myMatrix3.size(); ++i) {
        for (int j = 0; j < myMatrix3[i].size(); ++j) {
            std::cout << myMatrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}