#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
// Your task is to remove them from the list. "sweets" vector can help you with this
// You should erase every element from "list" vector that is not in "sweets" vector.
// No, don't just remove the lines
// Create a method called filter() which takes the two lists as parameters.

std::vector<std::string> filter(std::vector<std::string> inputVector1, std::vector<std::string> inputVector2){

    std::vector<std::string> filteredList;
    for (int i = 0; i < inputVector1.size(); ++i) {
        for (int j = 0; j < inputVector2.size(); ++j) {
                if(inputVector2[j] == inputVector1[i]) {
                    filteredList.push_back(inputVector2[j]);
                }
        }
    }
    return filteredList;
}

int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};



    std::vector<std::string> filteredList = filter(list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }

    return 0;
}
