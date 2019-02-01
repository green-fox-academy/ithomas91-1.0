#include <iostream>

/*Passing by value example

int add(int x);

int main() {


    int data = 10;
    data = add(data);
    std::cout<<"Value in data = "<< data<<std::endl;

    return 0;
}

int add(int x){

    int input;
    std::cout<< "Enter the value to be added to data!"<<std::endl;
    std::cin>> input;
    x = x + input;
    return x;

}

*/

// Paasing by reference example

void add(int &x);

int main() {

    int data = 10;
    add(data);

    std::cout<< "The value in data: "<< data <<std::endl;

    return 0;
}

void add(int &x){

    int input;
    std::cout<< "Enter the value to be added in data"<<std::endl;

    std::cin >> input;
    x = x + input;




}
