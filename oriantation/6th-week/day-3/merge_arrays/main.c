
#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* even_pointer = NULL;
    int lenght_of_arrays = 10;

    even_pointer = (int*)malloc(lenght_of_arrays * sizeof(int));
    for (int i = 0; i < lenght_of_arrays; ++i) {
        even_pointer[i] = (i + 1) * 2;
    }

    int* odd_pounter = NULL;
    odd_pounter = (int*)malloc(lenght_of_arrays * sizeof(int));
    for (int j = 0; j < lenght_of_arrays; ++j) {
        odd_pounter[j] = ((j + 1) * 2) - 1;
    }

    int lenght_of_result = (lenght_of_arrays * 2);
    realloc(even_pointer, lenght_of_result * sizeof(int));

    for (int k = 0; k < lenght_of_arrays; ++k) {
        even_pointer[lenght_of_arrays + k] = odd_pounter[k];
    }

    for (int l = 0; l < lenght_of_result; ++l) {
        printf("%d\t", even_pointer[l]);
    }

    free(even_pointer);
    free(odd_pounter);

    return 0;
}