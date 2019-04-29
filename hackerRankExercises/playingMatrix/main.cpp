#include <iostream>
#include <vector>

std::vector<std::vector<int>> myMatrix (std::vector<std::vector<int>> inputMatrix){

    std::vector<std::vector<int>> resultMatrix = inputMatrix;
    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix.size(); ++j) {
            resultMatrix[i][j] = inputMatrix[j][i];
        }
    }
    return resultMatrix;
}


int main() {


    std::vector<std::vector<int>> myMatrix1 = {{1, 2, 3},
                                               {4, 5, 6},
                                               {7, 8, 9}};

    std::vector<std::vector<int>> myMatrix2 = {{3, 2, 5},
                                               {4, 6, 1},

                                               {9, 4, 1}};


    std::vector<std::vector<int>> resultMatrix = myMatrix(myMatrix1);

    for (int i = 0; i < resultMatrix.size(); ++i) {
        for (int j = 0; j < resultMatrix.size(); ++j) {
            std::cout<< resultMatrix[i][j] << " ";
        }
        std::cout<<std::endl;
    }

    return 0;
}