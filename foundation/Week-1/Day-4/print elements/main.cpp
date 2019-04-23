#include <iostream>
#include <string>


// - Create (dynamically) a two dimensional array
//   with the following matrix. Use a loop!
//   by dynamically, we mean here that you can change the size of the matrix
//   by changing an input value or a parameter or this combined
//
//   1 0 0 0
//   0 1 0 0
//   0 0 1 0
//   0 0 0 1
//
// - Print this two dimensional array to the output

void createMatrix(int userInput){
    for (int i = 0; i < userInput; ++i) {
        for (int j = 0; j < userInput; ++j) {
            if(i == j){
                std::cout<< "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char* args[]) {

    int userInput;
    std::cout<<"Prease enter an integer to get the size of the matrix what i will make for you!"<<std::endl;
    std::cin>> userInput;

    createMatrix(userInput);

    return 0;
}