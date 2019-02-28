#include <stdio.h>
#include <stdlib.h>

// Create a program which asks for the age of the user and stores it
// Create a function which takes that age as a parameter and returns if the user is
// old enough to buy himself alcohol in Hungary

void checkAge(int _age)
{
    if(_age < 18){
        printf("You are too young to by Alcohol in Hungary, sais the law!");
    } else {
        printf("Here you go, Mate, have a nice one! Cheers!");
    }
}

int main()
{
    char name[20];
    int age;

    printf("Hi, You oK?, What is your name?\n");
    scanf("%s", name);

    printf("Hi %s, Nice to meet you!, how can i help?\n", name);

    printf("May i have 2 bottles of Soproni?\n");

    printf("How old are you?\n");
    scanf("%d", &age);

    checkAge(age);

    return 0;
}