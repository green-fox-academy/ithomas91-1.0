#include <iostream>
#include "login.h"
#include <vector>

void staircase(int n){

    for (int i = 0; i < n; ++i) {
        if(i == n -1){
            std::cout<<"#";
            n--;
        } else {
            std::cout<<" ";
        }
    }
}

int main() {

    staircase(6);

    return 0;
}