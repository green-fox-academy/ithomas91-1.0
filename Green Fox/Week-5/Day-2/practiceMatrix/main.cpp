#include <iostream>
#include <vector>

void sumRaw(std::vector<std::vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        std::cout << std::endl;
        for (int j = 0; j < matrix[i].size(); ++j) {
            int sum = 0;
            sum = matrix[i][j];
            //std::cout << matrix[i][j] << " " << std::endl;
            std::cout << sum;
        }

    }
}

int main()
{
    std::vector<std::vector<int>> myVector = {{1, 2, 3},
                                              {4, 5, 6},
                                              {7, 8, 9}};

    sumRaw(myVector);

    return 0;
}