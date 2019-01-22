#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
// Your task is to remove them from the list. "sweets" vector can help you with this
// You should erase every element from "list" vector that is not in "sweets" vector.
// No, don't just remove the lines
// Create a method called filter() which takes the two lists as parameters.

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
