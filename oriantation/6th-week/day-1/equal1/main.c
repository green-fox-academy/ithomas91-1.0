#include <stdio.h>

    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

int checkNumber(int Ainput, int Binput)
{
    if(Ainput == Binput ){
       printf("1");
        return 1;
    } else {
        printf("0");
        return 0;
    }
}

int main()
{
    int a;
    int b;

    printf("Enter 2 Integer please! \n");
    scanf("%d", &a);

    scanf("%d", &b);

    checkNumber(a, b);

    return 0;
}