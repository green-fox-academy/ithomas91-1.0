#include <iostream>
#include <vector>


// Write a method that joins the two lists by matching one girl with one boy into a new list
// If someone has no pair, he/she should be the element of the list too
// Exepected output: "Eve", "Joe", "Ashley", "Fred"...

std::vector<std::string> makePairs(std::vector<std::string> &inputVector1, std::vector<std::string> &inputVector2){
    std::vector<std::string> resultVector;
    int indexCounter = 0;
    for (int i = 0; i < inputVector2.size(); ++i) {
            resultVector.push_back(inputVector1[i] + "-" + inputVector2[i]);

    }
    return resultVector;
}

int main() {

    std::vector<std::string> girls = {"Eve","Ashley","Claire","Kat","Jane"};
    std::vector<std::string> boys = {"Joe","Fred","Tom","Todd","Neef","Jeff"};

    std::vector<std::string> resultVector = makePairs(girls, boys);

    for (int i = 0; i < resultVector.size(); ++i) {
        std::cout << resultVector[i] << "  ";
    }

    return 0;
}