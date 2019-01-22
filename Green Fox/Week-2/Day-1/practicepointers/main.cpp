#include <iostream>

void passingbyValue(int x);

void passbyreference(int *v);

int main() {

    int tomi = 25;
    int niki = 20;


passbyreference(&niki);

std::cout<< niki<<std::endl;

    return 0;
}

void passingbyValue(int x){
        x = 88;
}

void passbyreference(int *v){
       *v = 34;
}
