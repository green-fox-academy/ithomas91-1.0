#include <iostream>
#include <vector>

// Create a program which first asks for a number
// this number indicates how many integers we want to store in an array
// and than asks for numbers till the user fills the array
// It should print out the biggest number in the given array and the memory address of it

int main()
{

    std::cout << "Please, enter an integer, to fill up the array[5]" << std::endl;

    int a, b, c, d, e;
    std::vector<int> vector;

    std::cin >> a >> b >> c >> d >> e;

    vector.push_back(a);
    vector.push_back(b);
    vector.push_back(c);
    vector.push_back(d);
    vector.push_back(e);

    int maxValue = 0;

    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] >= maxValue){
            maxValue = vector[i];
        }
    }
    int *maxValuep = &maxValue;

    std::cout << "The biggest number is in the vector is: " << *maxValuep << std::endl;

    return 0;
}