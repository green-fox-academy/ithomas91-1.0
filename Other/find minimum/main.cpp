#include <iostream>

// Create a function which takes an array (and its length) as a parameter
// and returns a pointer to its minimum value
int func(int array[], int size){
    for (int i = 0; i < sizeof(array); ++i) {
        int smallest = array[0];
        if(array[i] < smallest){
            smallest = array[i];
        }
    }
}

int main()
{
    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    std::cout << func(numbers, sizeof(numbers));

    return 0;
}