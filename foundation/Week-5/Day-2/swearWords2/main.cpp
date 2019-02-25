#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


// There is a not so family friendly text in the `content.txt`
// Create a function named familyFriendlizer that takes a filename and a list of strings as parameters
// and remove all the given words from the file and returns the amount of the removed words.

int familyFriendlizer(std::string fileName, std::vector<std::string> offensiveWords)
{
    std::ifstream myFile(fileName);

    if(!myFile.is_open()){
        throw "File can not be opened";
    }

    std::string clearedText;
    std::string line;
    int removedWords = 0;

    while(getline(myFile, line)){
        std::stringstream stringStream;
        stringStream << line;
        std::string word;
        while(getline(stringStream, word, ' ')){
            for (int i = 0; i < offensiveWords.size(); ++i) {
                if(word == offensiveWords[i]){
                  removedWords++;
                } else {
                    clearedText += word + ' ';
                }
            }
        }
    }
    std::ofstream newFile;
    newFile.open("../clearedText.txt");

    newFile << clearedText;

    return removedWords;
}

int main()
{
    std::vector<std::string> offensiveWords = { "fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole", "dick", "piss" };

    std::cout << familyFriendlizer("../content.txt", offensiveWords) << std::endl;


    return 0;
}