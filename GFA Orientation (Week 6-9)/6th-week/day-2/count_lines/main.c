#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int count_lines(char *file_name)
{
    FILE *f_pointer;
    f_pointer = fopen(file_name, "r");

    if (f_pointer == NULL) {
        return -1;
    }
    int line_counter = 0;
    char file_line[150];
    while (!feof(f_pointer)) {
        fgets(file_line, 150, f_pointer);
        line_counter++;
    }
    return line_counter;
}

int main()
{
    printf("The input file has %d lines.",count_lines("../file.txt"));
    return 0;
}