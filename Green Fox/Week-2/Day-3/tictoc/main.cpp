#include <iostream>
#include <fstream>
#include <string>

// Write a function that takes a filename as string,
// open and read it. The file data represents a tic-tac-toe
// game result. Return 'X'/'O'/'draw' based on which player
// has winning situation.

std::string tcTacResult(std::string fileName){
    std::ifstream myFile(fileName);
    int array[3][3];
    std::string line;
    int i = 0;
    while(std::getline(myFile, line))
    {
        array[i][0] = line[0];
        array[i][1] = line[1];
        array[i][2] = line[2];
        i ++;
    }


}

int main() {


    std::cout << ticTacResult("win-o.txt");
    // should print O

    std::cout << ticTacResult("win-x.txt");
    // should print X

    std::cout << ticTacResult("draw.txt");
    // should print draw

    return 0;
}