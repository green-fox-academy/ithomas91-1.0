#include <iostream>
#include <fstream>
#include <map>

char mostCommon(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName);

    if(!myFile.is_open()){
        throw std::string ("File does not exist!");
    }

    std::map<char, int> charactersToNumbers;
    std::string line;
    while(std::getline(myFile, line)){
        for (int i = 0; i < line.size(); ++i) {
            char a = line[i];
            if(charactersToNumbers.find(a) == charactersToNumbers.end()){
                charactersToNumbers[a] = 1;
            } else {
                charactersToNumbers[a]+= 1;
            }
        }
    }
}

int main() {


    return 0;
}