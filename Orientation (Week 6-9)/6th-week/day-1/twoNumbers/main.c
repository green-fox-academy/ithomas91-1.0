#include<stdio.h>

// Create a program that prints a few operations on two numbers: 22 and 13

// Print the result of 13 added to 22

// Print the result of 13 substracted from 22

// Print the result of 22 multiplied by 13

// Print the result of 22 divided by 13 (as a decimal fraction)

// Print the reminder of 22 divided by 13


// Store the results in variables and use them when you display the result

int main()
{
    printf("Here is some operations of 22, and 13\n");

    int a = 22;
    int b = 13;

    int c = a + b;
    printf("a + b = %d \n", c );

    int d = b - a;
    printf("b - a = %d \n", d);

    int e = a * b;
    printf("a * b = %d\n", e);

    float f = a / b;
    printf("a / b = %f\n", f);




    return 0;
}