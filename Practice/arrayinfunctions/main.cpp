#include <iostream>


void printout(int theArray[], int sizeOfArray);


int main() {

    int niki[7] = {8, 18 ,27, 32,48, 7, 10};
    int tomi[5] = {2, 12, 22, 3, 33};

    printout(tomi, 5);

    return 0;
}
void printout(int theArray[], int sizeOfArray) {

    for(int i = 0; i < sizeOfArray; i++)

    std::cout<< theArray[i] <<std::endl;

}
