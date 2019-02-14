#include <iostream>
#include <fstream>
#include <map>

void entranceUsage(std::string inputFileName, std::string outputFileName)
{
    std::ifstream inputFile;
    inputFile.open(inputFileName);

    if (!inputFile.is_open()) {
        throw "File does not exist!";
    }
    std::string name;
    std::string type;
    std::string date;
    std::map<std::string, int> doorUsageType;

    while (inputFile >> name >> type >> date) {
        doorUsageType[type]++;
    }

    inputFile.close();

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    std::string result;
    result = "Building usage";

    for (std::map<std::string, int>::iterator it = doorUsageType.begin(); it != doorUsageType.end(); ++it) {
        outputFile << it->first << ":" << it->second << std::endl;
    }
}

int main()
{
    entranceUsage("../example.txt", "../result.txt");
    return 0;
}