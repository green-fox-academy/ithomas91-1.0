#include <iostream>
#include <vector>
std::vector<std::vector<int>> combineMatrix(std::vector<std::vector<int>> _matrix1,
                                            std::vector<std::vector<int>> _matrix2)
{
    std::vector<std::vector<int>> matrix3(_matrix1.size(), std::vector<int>(_matrix1.size()));


    for (int i = 0; i < _matrix1.size(); ++i) {
        for (int j = 0; j < _matrix1[i].size(); ++j) {
            if (_matrix1[i][j] >= _matrix2[i][j]) {
                matrix3[i][j] += _matrix1[i][j];
            } else if (_matrix2[i][j] > _matrix1[i][j]) {
                matrix3[i][j] += _matrix2[i][j];
            }
        }
    }
    return matrix3;
}
    int main()
    {

        std::vector<std::vector<int>> matrix1 = {{1, 2, 3},
                                                 {4, 5, 6},
                                                 {7, 8, 9}};

        std::vector<std::vector<int>> matrix2 = {{9, 8, 7},
                                                 {6, 5, 4},
                                                 {3, 2, 1}};


        std::vector<std::vector<int>> matrix3 = combineMatrix(matrix1, matrix2);
        for (int i = 0; i < matrix3.size(); ++i) {
            for (int j = 0; j < matrix3[i].size(); ++j) {
                std::cout << matrix3[i][j] << " ";
            }
            std::cout << std::endl;
        }

        return 0;
    }