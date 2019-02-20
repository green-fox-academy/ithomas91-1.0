#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copyFile(std::string inputFileName, std::string outputFileName)
{
    bool status = false;

    std::ifstream inputFile;
    inputFile.open(inputFileName);
    std::ofstream outputFile;
    outputFile.open(outputFileName);

    std::string inLine;

    while(std::getline(inputFile, inLine)){
        outputFile << inLine << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::ifstream test(outputFileName);
    std::string testLine;

    while(std::getline(test, testLine)){
    }

    for (int i = 0; i < testLine.size(); ++i) {
        if(inLine[i] == testLine[i]){
            status = true;
        }
    }
    return status;
}

int main() {

    if(copyFile("myfile.txt", "newfile.txt")){
        std::cout << "Copy was succesfull!";
    } else {
        std::cout << "Copy wasn't succesfull";
    }
    return 0;
}