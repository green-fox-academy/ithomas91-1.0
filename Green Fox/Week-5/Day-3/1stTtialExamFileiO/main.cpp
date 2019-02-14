#include <iostream>
#include <fstream>
#include <map>
/*Write a function that takes a filename as a parameter.
Return the most common character of the file's content.
If the file does not exist throw an exception with the following message:
"File does not exist!"*/

char findMostCommonChar(std::string fileName)
{
    std::ifstream myFile(fileName);

    if(!myFile.is_open()){
        throw "File does not exist!";
    }

    std::map<char, int> charToNumbers;
    std::string line;

    while(std::getline(myFile, line)){
        for (int i = 0; i < line.size(); ++i) {
           char c = line[i];
           if(charToNumbers.find(c) == charToNumbers.end()){
               charToNumbers[c] = 1;
           } else {
               charToNumbers[c] += 1;
           }
        }
    }

    std::pair<char, int> mostCommonCharacter = *charToNumbers.begin();
        for(std::map<char, int>::iterator it = charToNumbers.begin(); it != charToNumbers.end(); it++){

        }

}

int main()
{



    return 0;
}