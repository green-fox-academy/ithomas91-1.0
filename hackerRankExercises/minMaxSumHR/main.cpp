#include <iostream>
#include <vector>

void miniMaxSum(std::vector<int> arr) {

    unsigned int min = UINT32_MAX;
    int max = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    for (int k = 0; k < arr.size(); ++k) {
        if(arr[k] > max){
            max = arr[k];
        }
    }

    long long sumArray = 0;
    for (int j = 0; j < arr.size(); ++j) {
        sumArray += arr[j];
    }

    long minSum = sumArray - min;
    long maxSum = sumArray - max;

    std::cout<<min<<std::endl;
    std::cout<<max<<std::endl;
    std::cout<<sumArray<<std::endl;

    //std::cout<<maxSum<<" "<<minSum;
}

int main() {

    std::vector<int> vector = {769082435, 210437958, 673982045, 375809214, 380564127};

    miniMaxSum(vector);

    return 0;
}