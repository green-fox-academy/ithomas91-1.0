#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.


char *concatenate_springs(char *first, char *second)
{
    char *result;

    result = (char *) malloc(strlen(first) + strlen(second) * sizeof(char));
    strcpy(result, first);
    strcat(result, second);

    return result;


}

int main()
{
    char first_string[20];
    char second_string[20];

    printf("Enter a string please!\n");
    scanf("%s", first_string);

    printf("Enter a another string please!\n");
    scanf("%s", second_string);

    printf("%s", concatenate_springs(first_string, second_string));

    free(concatenate_springs(first_string, second_string));

    return 0;
}