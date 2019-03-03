#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void write_word_into_lines(char file_name[], char input_word[], int number_of_lines)
{
    FILE *f_pointer;
    f_pointer = fopen(file_name, "w");
    for (int i = 0; i < number_of_lines; ++i) {
        fprintf(f_pointer, "%s\n", input_word);
    }
    fclose(f_pointer);
}

int main()
{
    char file_path[] = "../my-file.txt";
    char word_to_write[] = "apple";
    int number_of_lines = 4;
    write_word_into_lines(file_path, word_to_write, number_of_lines);

    return 0;
}