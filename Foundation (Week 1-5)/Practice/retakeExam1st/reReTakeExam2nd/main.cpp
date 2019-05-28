#include <iostream>
#include <fstream>
#include <map>

void organiseData(std::string fileName)
{

    std::ifstream myFile;
    myFile.open(fileName);

    if (!myFile.is_open()) {
        throw std::string("File cannot be read");
    }
    std::string firstLine;
    std::getline(myFile, firstLine);

    int dunaLevel;
    int tiszaLevel;
    int year;
    std::map<int, int> dunaLevelsYear;
    std::map<int, int> tiszaLevelsYear;

    while (myFile >> dunaLevel >> tiszaLevel >> year) {
        dunaLevelsYear[year] = dunaLevel;
        tiszaLevelsYear[year] = tiszaLevel;
    }

    int dunaMax = 0;
    int dunaMaxYear = 0;
    int dunaMin = 10000;
    int dunaMinYear;

    for (std::map<int, int>::iterator it = dunaLevelsYear.begin(); it != dunaLevelsYear.end(); ++it) {
        if (it->second > dunaMax) {
            dunaMax = it->second;
            dunaMaxYear = it->first;
        }

        if (it->second < dunaMin) {
            dunaMin = it->second;
            dunaMinYear = it->first;
        }
    }

    int tiszaMax = 0;
    int tiszaMaxYear = 0;
    int tiszaMin = 10000;
    int tiszaMinYear;

    for (std::map<int, int>::iterator it = tiszaLevelsYear.begin(); it != tiszaLevelsYear.end(); ++it) {
        if (it->second > tiszaMax) {
            tiszaMax = it->second;
            tiszaMaxYear = it->first;
        }

        if (it->second < tiszaMin) {
            tiszaMin = it->second;
            tiszaMinYear = it->first;
        }
    }

    std::cout << "Duna" << std::endl;
    std::cout << "lowest: " << dunaMinYear << std::endl;
    std::cout << "highest " << dunaMaxYear << std::endl;

    std::cout << "Tisza" << std::endl;
    std::cout << "lowest: " << tiszaMinYear << std::endl;
    std::cout << "highest " << tiszaMaxYear << std::endl;
}
int main()
{
    try {
        organiseData("../results.txt");
    } catch (std::string s) {
        std::cerr << s << std::endl;
    }
}