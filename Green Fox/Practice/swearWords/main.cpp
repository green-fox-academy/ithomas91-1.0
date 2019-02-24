#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


//There is a not so family friendly text in the `content.txt`
    // Create a function named familyFriendlizer that takes a filename and a list of strings as parameters
    // and remove all the given words from the file and returns the amount of the removed words.

    int familyFriendlizer(std::string fileName, std::vector<std::string> wordsToRemove)
    {
        std::ifstream myFile;
        myFile.open(fileName);

        if(!myFile.is_open()){
            throw std::string ("File can't be opened!");
        }

        int swearWordsCounter = 0;
        std::string line;
        std::string clearedText;

        while(getline(myFile, line)){
            std::stringstream stringStream;
            stringStream << line;
            std::string word;

            while (getline(stringStream, word, ' ')){
                for (int i = 0; i < wordsToRemove.size(); ++i) {
                    if(word != wordsToRemove[i]){
                        clearedText += word + ' ';
                    } else {
                        swearWordsCounter++;
                    }
                }
            }
        }
        std::ofstream newFile;
        newFile.open("../clearedText.txt");

        newFile << clearedText;

        return swearWordsCounter;
    }

int main() {

    std::vector<std::string> offensiveWords = {"fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole",
                                              "dick", "piss"};

    std::cout << familyFriendlizer("content.txt", offensiveWords) << std::endl;

    return 0;
}