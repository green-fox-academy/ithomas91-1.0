#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

std::map<std::string, int> chipUsage(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName);

    if (!myFile.is_open()) {
        throw std::string("File can not be opened!");
    }

    std::map<std::string, int> result;
    std::string line;
    std::string cardType;

    while (std::getline(myFile, line)) {
        std::stringstream stringStream(line);
        std::string data; // to get data individually
        int countData = 0;
        std::string cardNumber;
        std::string mainEntrance;
        while (std::getline(stringStream, data, ',')) {
            //std::cout << data <<std::endl;
            if (countData == 5) {
                mainEntrance = data;
            } else if (countData == 12) {
                cardNumber = data;
            }
            countData++;
        }
        if (mainEntrance == "A66 - 04 FÕBEJÁRAT (F-1) Door #1") {
            result[cardNumber]++;
        }

    }
    return result;
}

int main()
{
    std::map<std::string, int> finalResult = chipUsage("../data.txt");

    for (std::map<std::string, int>::iterator it = finalResult.begin(); it != finalResult.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}