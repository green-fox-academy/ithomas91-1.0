#include <stdio.h>
#include <stdlib.h>

// Create a program which asks for a number and stores it
// Create a function which takes a number as a parameter and
// returns 1 if that number is even and returns 0 otherwise
// (in this case 0 is an even number)

int checkEvenOdd(int inputNumber)
{
    if (inputNumber % 2 == 0) {
        printf("1");
        return 1;
    } else {
        printf("0");
        return 0;
    }
}

int main()
{
    int userInput;
    printf("Enter an integer to check if EVEN or ODD!\n");
    scanf("%d", &userInput);

    checkEvenOdd(userInput);

    return 0;
}