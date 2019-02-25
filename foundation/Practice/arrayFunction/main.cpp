#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix(std::vector<std::vector<int>> inputMatrix) {
    std::vector<int> tempMatrix = {1, 2, 3, 4};
    std::vector<int> tempMatrix2;
    for (int i = 0; i < inputMatrix.size(); ++i) {
        for (int j = 0; j < inputMatrix.size(); ++j) {
           tempMatrix2[i] = inputMatrix;
            inputMatrix[i][j] = tempMatrix[i];
        }
        std::cout << std::endl;
    }
    return inputMatrix;
}

int main() {

    std::vector<std::vector<int>> myVector = {{6, 3, 9,  12,},
                                              {5, 2, 88, 21},
                                              {2, 4, 43, 23}};

    std::vector<std::vector<int>> newMatrix = matrix(myVector);
    for (int i = 0; i < newMatrix.size(); ++i) {
        for (int j = 0; j < newMatrix.size(); ++j) {
            std::cout << myVector[i][j] <<" ";
        }

    }

    return 0;
}


/*********************************************
 sort(myVector.begin(), myVector.end());
    for (int i = 0; i < myVector.size(); ++i){
        std::cout << myVector[i] << " ";
    }

*********************************************/