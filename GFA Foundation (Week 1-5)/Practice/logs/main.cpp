#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> getIP(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName);

    if (!myFile.is_open()) {
        throw std::string("File cannot be opened!");
    }

    std::vector<std::string> iPvector;
    std::string dayName;
    std::string month;
    std::string day;
    std::string time;
    std::string year;
    std::string iP;
    std::string type;
    std::string sign;

    while (myFile >> dayName >> month >> day >> time >> year >> iP >> type >> sign) {
        iPvector.push_back(iP);
    }
    myFile.close();

    return iPvector;

}

double getRatio(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName);

    if (!myFile.is_open()) {
        throw std::string("File cannot be opened!");
    }

    std::vector<std::string> iPvector;
    std::string dayName;
    std::string month;
    std::string day;
    std::string time;
    std::string year;
    std::string iP;
    std::string type;
    std::string sign;
    int postCounter = 0;
    int getCounter = 0;

    while (myFile >> dayName >> month >> day >> time >> year >> iP >> type >> sign) {
        if (type == "POST") {
            postCounter++;
        } else {
            getCounter++;
        }
    }
    return getCounter / postCounter;
}
int main()
{

    std::vector<std::string> iPadresses = getIP("../logs.txt");
    for (int i = 0; i < iPadresses.size(); ++i) {
        std::cout << iPadresses[i] << std::endl;
    }

    double ratio = getRatio("../logs.txt");
    std::cout << "The ratio of the types is: " << ratio;

    return 0;
}