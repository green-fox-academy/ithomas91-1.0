#include<stdio.h>

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Your height in meters (as a decimal fraction)
//
//  Use variables to store the informations!
//
//  Example output:
//  John Doe
//  31
//  1.87


int main()
{
    char name[20];
    int age;
    float height;

    printf("Enter your name please! \n");
    gets(name);

    printf("Enter your age please\n");
    scanf("%d", &age);

    printf("Enter your heigh please. you can use float\n");
    scanf("%f", &height);

    printf("My name is %s and i am %d years old. i am %f meters tall", name, age, height);

    return 0;
}