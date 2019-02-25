#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

std::map<std::string, int> chipUsage(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName);

    if(!myFile.is_open()){
        throw std::string("File can not be opened!");
    }

    std::map<std::string, int> result;
    std::string line;
    std::string cardType;
    int chipUsage = 0;

    while(std::getline(myFile, line)){
        std::stringstream stringStream(line);
        std::string data; // to get data individually

        while (std::getline(stringStream, data, ',')){
            result[cardType]+= chipUsage;
            if()
        }
    }
}

int main()
{
    chipUsage("../data.txt");
    return 0;
}