#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

char *binary_to_ascii(char *input_char)
{
    char result = 0;
    int lenght = strlen(input_char);

    for (int i = 0; i < lenght; ++i) {
        char c = input_char[i];
        if (c == '1') {
            int power = lenght - 1 - i;
            result += (1 << power);
        }
    }
    return result;
}

char *convert_file_to_ascii(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!!!");
        return NULL;
    }

    char *result_string = (char *) malloc(sizeof(char));
    int i_cointer = 0;

    char buffer_string[10];
    while (fgets(buffer_string, 10, file_pointer) != NULL) {
        buffer_string[8] = '\0';
        char result = binary_to_ascii(buffer_string);
        result_string[i_cointer] = result;
        i_cointer++;
        result_string = (char *) realloc(result_string, (i_cointer + 1) * sizeof(char));
    }
    result_string[i_cointer] = '\0';
    fclose(file_pointer);
    return result_string;
}

int main()
{

    char *text = convert_file_to_ascii("../input.txt");
    printf("%s ", text);

    free(text);
    return 0;
}