#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef enum
{
  BETWEEN_15_AND_20,
  BETWEEN_20_AND_25,
  BETWEEN_25_AND_30,
  BETWEEN_30_AND_35,
  BETWEEN_35_AND_40
} age_groups;

typedef struct
{
  char *name;
  int year;
  int month;
  int day;
} persons_t;

/*
Implement the functions used below, and make the program work.
*/


persons_t *get_persons(char *file_name, int *number_persons)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!");
    }

    char buffer[100];
    unsigned int counter = 0;

    while (!feof(file_pointer)) {
        fgets(buffer, 100, file_pointer);
        counter++;
    }

    *number_persons = counter;
    fclose(file_pointer);

    persons_t *persons = (persons_t *) malloc(sizeof(persons_t) * counter);

    file_pointer = fopen(file_name, "r");

    int i;
    char *name;
    char *year;
    char *month;
    char *day;
    for (i = 0; i < counter; ++i) {
        fgets(buffer, 100, file_pointer);

        name = strtok(buffer, ",");
        year = strtok(NULL, "-");
        month = strtok(NULL, "-");
        day = strtok(NULL, "-");

        persons[i].name = name;
        persons[i].year = atoi(year);
        persons[i].month = atoi(month);
        persons[i].day = atoi(day);

        printf("name : %s date of birth: %d. %d. %d.\n",
               persons[i].name,
               persons[i].year,
               persons[i].month,
               persons[i].day);
    }

    return 0;
}

void get_vowels(char *file_name)
{

    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!");
    }

    char *vowels = "aeiouAEIOU";
    unsigned int index_counter = 0;
    char *vowels_buffer = (char *) malloc(sizeof(char));
    char current_char;

    while (!feof(file_pointer)) {
        current_char = fgetc(file_pointer);
        for (int j = 0; j < strlen(vowels); ++j) {
            if (current_char == vowels[j]) {
                vowels_buffer[index_counter] = current_char;
                index_counter++;

                vowels_buffer = realloc(vowels_buffer, (index_counter + 1) * sizeof(char));
            }
        }
    }

    FILE *output_file;
    output_file = fopen("../output.txt", "w");

    fprintf(output_file, "%s ", vowels_buffer);

    fclose(output_file);

}

age_groups get_age_group(persons_t person)
{
    int current_year = 2019;
    int person_age = 2019 - person.year;

    if (person_age > 15 && person_age < 20) {
        printf("BETWEEN_15_AND_20");
        return BETWEEN_15_AND_20;
    }
    if (person_age > 20 && person_age < 25) {
        printf("BETWEEN_20_AND_25");
        return BETWEEN_20_AND_25;
    }
    if (person_age > 25 && person_age < 30) {
        printf("BETWEEN_25_AND_30");
        return BETWEEN_25_AND_30;
    }
    if (person_age > 30 && person_age < 35) {
        printf("BETWEEN_30_AND_35");
        return BETWEEN_30_AND_35;
    }
    if (person_age > 35 && person_age < 40) {
        printf("BETWEEN_35_AND_40");
        return BETWEEN_35_AND_40;
    }

}

int main()
{
    int nmbr_of_persons;

    persons_t *persons = get_persons("../input.txt", &nmbr_of_persons);
    get_vowels("../input.txt");
    /*
    This function should read persons data from a text file
    and return the datas into a structure-array.
    As you can see, you have to use dynamic memory allocation.
    */


   // list_persons_in_age_group(persons, nmbr_of_persons, BETWEEN_30_AND_35);

    persons_t *array[2];

    array[0]->name = "Tomi";
    array[0]->year = 1991;
    array[0]->month = 3;
    array[0]->day = 28;

    array[1]->name = "Valaki";
    array[1]->year = 1976;
    array[1]->month = 6;
    array[1]->day = 15;

    persons_t person;
    person.name = "Teszt";
    person.year = 1991;
    person.month = 2;
    person.day = 12;

    get_age_group(person);

    /*
    This function should print out the filtered informations based on the given age group
    to the console in the following way:
    Persons in the given age group:
    Pop Simon, aged 28
    Major Anna, aged 26
    */



    return 0;
}
