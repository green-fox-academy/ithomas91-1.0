#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_binary(char file_name[])
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!");
    }
    char file_buffer[50000];

    fgets(file_buffer, 50000, file_pointer);
    puts(file_buffer);

    char *token = strtok(file_buffer, " ");

    char temp_number;
    char *temp_char;

    while (!token == NULL) {


            temp_number = strtol(token, &temp_char, 2);
            printf("%c", temp_number);

        token = strtok(NULL, " ");
    }

    fclose(file_pointer);

    FILE *output_file;
    output_file = fopen("../output.txt", "w");

    for (int i = 0; i < sizeof(file_buffer); ++i) {

        temp_number = strtol(&file_buffer[i], &temp_char, 2);
        fprintf(output_file, "%c", temp_number);

    }

    token = strtok(NULL, " ");

    fclose(output_file);

}

int main()
{
    read_binary("../input.txt");
    return 0;
}