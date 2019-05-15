#include <iostream>
#include <vector>

int birthdayCakeCandles(std::vector<int> ar) {

    int canBlow = 0;
    int max = 0;

    for(int i = 0; i < ar.size(); i++){
        if(ar[i] > max){
            max = ar[i];
        }
    }
    for(int j = 0; j < ar.size(); j++ ){
        if(ar[j] == max){
            canBlow++;
        }
    }
    return canBlow;
}

int main() {

    std::vector<int> vector = {1, 2, 3, 4, 5, 5, 5, 3, 2, 5, 7, 7};
    int canBlow = birthdayCakeCandles(vector);

    std::cout<<canBlow << " Number of candles can blow!";

    return 0;
}