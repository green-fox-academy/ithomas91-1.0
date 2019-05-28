#include <stdio.h>
#include <memory.h>

int main()
{

    char practiceStrToken[] = ("Hi i am practicing str Token.");
    char *word = strtok(practiceStrToken, " .");

    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " .");
    }

    return 0;
}