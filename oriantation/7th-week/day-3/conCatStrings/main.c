#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concatenes(char *first_input, char *second_input)
{
    char *result;
    result = (char *) malloc((strlen(first_input) + strlen(second_input)) * sizeof(char));
    strcpy(result, first_input);
    strcat(result, second_input);
    return result;
}

int main()
{
    char *user_input1;
    char *user_input2;
   // printf("Can you please enter 2 strings to concatenates them?!\n");
   //scanf("%s" "%s", user_input1, user_input2);

   puts(concatenes("Tomi-", "Niki"));

    return 0;
}