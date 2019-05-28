#include <iostream>
#include <map>
#include <fstream>

std::map<std::string, float> getAvarageMatrics(std::string inputFileName)
{
    std::ifstream inputFile;
    inputFile.open(inputFileName);

    if (!inputFile.is_open()) {
        throw std::string("File does not opened!");
    }
    int numberOfResponses = 0;
    std::map<std::string, float> result;
    int m, p, h, e;

    while (inputFile >> m >> p >> h >> e) {
        result["matReview"] += m;
        result["preSkills"] += p;
        result["helpfulness"] += h;
        result["explanations"] += e;
        numberOfResponses++;
    }

    for (std::map<std::string, float>::iterator it = result.begin(); it != result.end(); ++it) {
        it->second /= numberOfResponses;
    }
    return result;
}



int main() {

    try {
        std::map<std::string, float> averageMetrics = getAvarageMatrics("data.txt");
        for (std::map<std::string, float>::iterator it = averageMetrics.begin(); it != averageMetrics.end(); ++it) {
            std::cout << it->first << ": " << it->second << std::endl;
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    return 0;
}