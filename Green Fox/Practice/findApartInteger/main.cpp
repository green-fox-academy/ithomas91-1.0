#include <iostream>
#include <string>
#include <vector>

//  Create a function that takes a string and a vector of string as a parameter
//  Returns the index of the string in the vector where the first string is part of
//  Only need to find the first occurence and return the index of that
//  Returns `-1` if the string is not part any of the strings in the vector

void subStrList(std::string string, std::vector<std::string> vector)
{
    if (std::find(vector.begin(), vector.end(), string) != vector.end()){
    }
}

int main(int argc, char *args[])
{


    //  Example:
    std::vector<std::string> searchArr = {"this", "is", "what", "I'm", "searching"};
    subStrList("ching", searchArr);
    //  should print: `4`
    subStrList("not", searchArr);
    //  should print: `-1`

    return 0;
}