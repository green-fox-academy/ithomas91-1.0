#include <iostream>
using namespace std;



// Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

//void swap(int *first_number, int *second_number){
void swap(int &first_number, int &second_number){

     int *third_number = &first_number;
     &first_number = second_number;
     second_number = *third_number;
}

int main ()
{

    int a = 10;
    int b = 316;
    cout<< a <<" "<<b<<endl;

    swap(a, b);
    cout<< a <<" "<<b<<endl;



    return 0;
}