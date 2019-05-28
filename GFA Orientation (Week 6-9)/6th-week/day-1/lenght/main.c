#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a program which asks for the name of the user and stroes it
// Create a function which takes a string as a parameter and returns the lenght of it
// Solve this exercie with and without using string.h functions

int string_lenght(char * input[])
{
    int size_input = strlen(input);

    return size_input;
}

int main()
{
    puts("Enter your name please\n");
    char name[20];
    gets(name);

    printf("The size of your name is: %d",strlen(name));

    return 0;
}