#include <iostream>
#include <vector>


// Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

void printValue(int a, int b, int c, int d, int e) {

    std::vector<int> vector;
    vector.push_back(a);
    vector.push_back(b);
    vector.push_back(c);
    vector.push_back(d);
    vector.push_back(e);

    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " "<<std::endl;
    }
}

int main()
{

    int a, b, c, d, e;

    std::cout<< "Please enter 5 integers next to each other, separated by space!" <<std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;


    printValue(a,b,c,d,e);

    return 0;
}