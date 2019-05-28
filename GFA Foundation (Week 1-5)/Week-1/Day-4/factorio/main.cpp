#include <iostream>
#include <string>

void factorio(int n, int& output);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int n;
    int output;


    std::cout << "Enter positive integer!" << std::endl;
    std::cin >> n;

    factorio(n, output);

    std::cout<< output << std::endl;

    return 0;
}

void factorio(int n, int& output) {

    int factorio = 1;

    for(int i = 1; i <= n; ++i){
    factorio *= i;


    }

    output = factorio;



}
