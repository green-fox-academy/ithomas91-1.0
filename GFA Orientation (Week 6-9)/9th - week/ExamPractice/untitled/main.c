#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int get_vowels(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!!!!");
        return -1;
    }

    int vowels_counter = 0;
    char *vowels = "aeouiAEOUI";
    char *vowels_for_output = (char*)malloc(sizeof(char));
    char *file_buffer = (char *) malloc(sizeof(char));
    vowels = (char *) malloc(strlen(vowels) * sizeof(char));


    while (fgets(file_buffer, 100, file_pointer)) {
        for (int i = 0; i < strlen(vowels); ++i) {
            for (int j = 0; j < strlen(file_buffer); ++j) {
                if (vowels[i] == file_buffer[j]) {
                    vowels_for_output += file_buffer[j];
                    vowels_counter++;
                }
            }
        }

    }


    fclose(file_pointer);

    FILE *output_file;
    output_file = fopen("../just_some_vowels.txt", "w");

    fprintf(output_file, "%s ", vowels_for_output);


    return vowels_counter;

}

int main()
{

    int result = get_vowels("../input.txt");
    printf(" Number of vowels is : %d", result);

    free(&result);
    return 0;

}