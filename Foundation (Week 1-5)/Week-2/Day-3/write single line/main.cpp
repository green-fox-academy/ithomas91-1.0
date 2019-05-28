#include <iostream>
#include <fstream>
#include <string>



// Open a file called "my-file.txt"
// Write your name in it as a single line

int main() {

    std:: ofstream myFile("my-file.txt");
    myFile << "Tamas Nemeth\n";


    return 0;
}