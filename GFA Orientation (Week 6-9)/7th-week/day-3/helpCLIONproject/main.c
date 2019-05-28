#include <stdio.h>
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

const char *byte_to_binary(int x)
{
    char* b = (char*)malloc(13 * sizeof(char));
    b[0] = '\0';

    int z;
    for (z = 1 << 3; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int main()
{

    int a = 15;
    for (int i = 0; i < 16; ++i) {
        printf("%s\n", byte_to_binary(i));
    }
    return 0;
}