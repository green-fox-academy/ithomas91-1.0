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
    int i = 0;
    int budget[50];
    int release_date[50];
    char **temp;

    while (!feof(file_pointer)) {
        fgets(file_buffer, 200, file_pointer);
        printf("%s\n", file_buffer);
        char *token = strtok(file_buffer, "$");
        printf("%s\n", token);

        char *profit = strtok(NULL, " ");
        printf("%s\n", profit);
        budget[i] = strtol(profit, temp, 10);
        printf("debug: %x %d\n", temp, budget[i]);

        char *year = strtok(NULL, "\n");
        printf("%s\n", year);
        release_date[i] = atoi(year);
        i++;

    }

    for (int j = 0; j < 50; ++j) {
        printf("budget: %d release date: %d \n ", budget[j], release_date[j]);
    }

    /*int counter = 0;
    int temp_year = 0;
    for (int k = 0; k < 50; ++k) {
        if(release_date[k] == ){
            counter++;
            temp_year = release_date[k];
        }
    }
    printf("year :%d how many: %d", temp_year, counter);
     */
}

int main()
{

    typedef struct movies
    {
      char title;
      int profit;
      int release_date;

    } movies_t;

    get_profit_and_successful_year("../file.txt");
    return 0;
}