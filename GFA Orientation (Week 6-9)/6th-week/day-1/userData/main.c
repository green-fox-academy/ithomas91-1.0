#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);



int main ()
{
    char user_data[200];
    char first_name[20];
    char last_name[20];
    char temp_age[16];
    int age = 0;

    puts("Please tell your first name, last name and your age, separated by SPACE! CHEERS!");
    gets(user_data);

    strcpy(first_name, strtok(user_data, " "));
    stpcpy(last_name, strtok(NULL, " "));
    age = atoi(strtok(NULL, " "));

    printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

    return 0;
}