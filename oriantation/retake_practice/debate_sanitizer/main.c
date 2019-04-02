#include <stdio.h>
#include <string.h>
#include <ctype.h>

void debate_sanitizer(char *user_input)
{
    char *result = user_input;
    int lenght_input = strlen(user_input);

    for (int i = 1; i < lenght_input; ++i) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + 32;
        } else if ((result[i] == '!') || (result[i] == '?') || (result[i] == '.')) {
            result[i] = NULL;
        }

    }
    printf("%s ", result);
}

int main()
{
    char *test;
    printf("Enter any string: \n");
    gets(test);

    debate_sanitizer(test);

    return 0;
}