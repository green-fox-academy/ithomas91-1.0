#include <iostream>
#include <vector>
#include <string>

void lookingForMaganhangzo(std::vector<std::string> words, std::string _temp, std::string maganH)
{
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < maganH.size(); ++j) {
            if(words[i] == maganH[j]){
                _temp += words[i];
            }
        }
        std::cout << _temp;
    }
}

int main()
{
    std::vector<std::string> offensiveWords = { "fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole", "dick", "piss" };
    std::string maganH = "aAeEoEuUiI";
    std::string temp;


    return 0;
}