#include <iostream>
#include <fstream>
#include <string>


// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file


int func(std::string filename){
    int count = 0;
    std::string line;

    std::ifstream file (filename);
    if (file.is_open()) {


        while (std::getline(file, line)) {
            count++;

        }
        return count;
    }else {
        return 0;

    }

}

int main () {
    int count = 0;
    std::string line;
    std::string filename;
    std::cout<<" Enter a file name!"<<std::endl;
    std::cin >> filename;

        std::cout<< "Numbers of lines in the file: " << func(filename) <<std::endl;

    return 0;
}