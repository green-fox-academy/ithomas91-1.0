#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//In the file you can find the best grossing movies in the format: [Title] [Profit] [Release date]
//Make a function that reads the data and returns a pointer to the data and the size. The function should not use more memory than necessary.
//Print the summed profit grouped by year
//Which was the most successful year in the movie industry?


char *get_profit_and_successful_year(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!");
    }

    char *file_buffer;
    file_buffer =(char*)malloc(sizeof(char));
    uint8_t number_of_lines = 0;
    char **temp;

      char *title;
      title = (char *)malloc(sizeof(char));
      int *profit;
      int *release_date;



    while (!feof(file_pointer)) {
        fgets(file_buffer, 200, file_pointer);
        number_of_lines++;
        //printf("%s  %d, \n", file_buffer, number_of_lines);
        char *token = strtok(file_buffer, " ");
        strcpy(title, token);
        //printf("%s \n", token);

    }

    printf("%s ", title);
}

int main()
{


    get_profit_and_successful_year("../file.txt");
    return 0;
}