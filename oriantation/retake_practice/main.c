#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int count_vowels(char *file_name)
{
    FILE *file_ponter;
    file_ponter = fopen(file_name, "r");

    if (file_ponter == NULL) {
        printf("File cannot be open.");
        return -1;
    }

    char *vowels_buffer = (char*)malloc(sizeof(char));
    char *vowels = "aeiouAEIOU";

    unsigned int counter_vowels = 0;
    char current_char;
    int index_counter = 0;

    while (!feof(file_ponter)) {
        current_char = fgetc(file_ponter);
        for (int i = 0; i < strlen(vowels) ; ++i) {
            if (current_char == vowels[i]) {
                counter_vowels++;
                vowels_buffer[index_counter] = vowels[i];
                index_counter++;

                vowels_buffer = realloc(vowels_buffer, (index_counter + 1) * sizeof(char));
            }
        }
    }


    fclose(file_ponter);

    FILE *output_file;
    output_file = fopen("../output.txt", "w");

    fprintf(output_file, "%s ", vowels_buffer);

    fclose(output_file);



    return counter_vowels;

}


int main()
{

    int result = count_vowels("../input.txt");

    printf("The number of the vowels in the file is : %d \n", result);

    free(result);

    return 0;
}