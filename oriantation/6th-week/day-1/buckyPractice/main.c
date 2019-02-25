#include <stdio.h>

int main()
{
    char myName[20];
    char myLove[20];
    int numbersOfBabys;

    printf("What is your name\n");
    scanf("%s", myName);

    printf("What is your love's name?\n");
    scanf("%s", myLove);

    printf("How many kids do you want?\n");
    scanf("%d", &numbersOfBabys);

    printf("Hi my name is %s and i am in love with %s and we want %d kid", myName, myLove, numbersOfBabys);

    return 0;
}