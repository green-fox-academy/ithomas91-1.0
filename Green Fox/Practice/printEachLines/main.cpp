#include <iostream>
#include <fstream>
#include <string>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, you may use C-programming, although it is not mandatory


void printLines(std::string fileName)
{
    std::ofstream myFile("myfile.txt");

    myFile << "Mon Feb  5 10:47:12 2018   32.28.73.45   POST /\n"
              "Mon Feb  5 10:47:12 2018   87.46.97.74   POST /\n"
              "Mon Feb  5 10:47:12 2018   60.56.36.21   POST /\n"
              "Mon Feb  5 10:47:12 2018   60.74.92.50   POST /\n"
              "Mon Feb  5 10:47:12 2018   79.37.20.41   GET /\n"
              "Mon Feb  5 10:47:12 2018   99.70.32.29   POST /";
    myFile.close();


    std::ifstream myFile2;
    myFile2.open(fileName);


    std::string line;

    while(std::getline(myFile2, line)){
        std::cout << line << std::endl;
    }
    myFile2.close();

}

int main () {

    printLines("myfile.txt");

    return 0;
}