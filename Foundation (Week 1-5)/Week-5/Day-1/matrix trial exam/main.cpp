#include <iostream>
#include <vector>

int main()
{

    std::vector<std::vector<int>> matrix = std::vector<std::vector<int>>(5, std::vector<int>(5));
    for (int i = 0; i < matrix.size(); ++i) {
        std::cout << std::endl;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if(i == j) {
                matrix[i][j] = 0;
            } else if(i > j){
                matrix[i][j] = 1;
            } else{
                matrix[i][j] = 2;
            }
            std::cout << matrix[i][j] << " ";


        }

    }



    return 0;
}