#include <iostream>
#include <string>


// - Create an array variable named `r`
//   with the following content: `[54, 23, 66, 12]`
// - Print the sum of the second and the third element


int main(int argc, char* args[]) {

    int r[] = {54, 23, 66, 12};

    std::cout << "The Sum of 2nd and 3rd element is: " << r[1] + r[2]<<std::endl;

    return 0;
}