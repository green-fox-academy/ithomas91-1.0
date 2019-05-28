#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int *pointer = NULL;
    int X;
    printf("Please enter an integer!\n");
    scanf("%d", &X);

    pointer = (int *) malloc(X * sizeof(int));
    for (int i = 0; i < X; ++i) {
        printf("Please enter your numbers %d: \n", i + 1);
        scanf("%d", &pointer[i]);
    }

    int Y = 0;
    for (int i = 0; i < X; ++i) {
        Y += pointer[i];
    }

    realloc(pointer, Y * sizeof(int));

    for (int j = 0; j < Y; ++j) {
        printf("Enter the %d element's value please\n", j + 1);
        scanf("%d", &pointer[j]);
    }

    for (int k = 0; k < Y; ++k) {
        printf("Value of the element %d. is %d", k + 1, pointer[k]);
    }
    return 0;
}