#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void lowest_median(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File cannot be opened!");
        return;
    }

    unsigned short number_of_lines = 0;

    char first_line[200];
    int first_array[14];

    char second_line[200];
    int second_array[12];

    char third_line[200];
    int third_array[15];

    char fourth_line[200];
    int fourth_array[15];

    while (!feof(file_pointer)) {
        char file_buffer[501];
        fgets(file_buffer, 500, file_pointer);
        number_of_lines++;

        // GET FIRST LINE OF THE FILE

        for (int i = 0; i < strlen(file_buffer); ++i) {
            if (number_of_lines == 1) {
                strcpy(first_line, file_buffer);
            }
        }

        // GET SECOND LINE OF THE FILE

        for (int i = 0; i < strlen(file_buffer); ++i) {
            if (number_of_lines == 2) {
                strcpy(second_line, file_buffer);
            }
        }

        // GET THIRD LINE OF THE FILE

        for (int i = 0; i < strlen(file_buffer); ++i) {
            if (number_of_lines == 3) {
                strcpy(third_line, file_buffer);
            }
        }

        // GET FOURTH LINE OF THE FILE

        for (int i = 0; i < strlen(file_buffer); ++i) {
            if (number_of_lines == 4) {
                strcpy(fourth_line, file_buffer);
            }
        }
    }

    // GET FIRST LINE'S NUMBERS TO ARRAY

    int index_counter_1 = 0;
    char *token = strtok(first_line, ":");
    while (token != NULL) {
        token = strtok(NULL, ",\n");
        if (token != NULL) {
            int temp = atoi(token);
            first_array[index_counter_1] = temp;
            index_counter_1++;
        }
    }

    // GET SECOND LINE'S NUMBERS TO ARRAY

    int index_counter_2;
    char *token2 = strtok(second_line, ":");
    while (token2 != NULL) {
        token2 = strtok(NULL, ",\n");
        if (token2 != NULL) {
            int temp = atoi(token2);
            second_array[index_counter_2] = temp;
            index_counter_2++;
        }
    }

    // GET THIRD LINE'S NUMBERS TO ARRAY

    int index_counter_3 = 0;
    char *token3 = strtok(third_line, ":");
    while (token3 != NULL) {
        token3 = strtok(NULL, ",\n");
        if (token3 != NULL) {
            int temp = atoi(token3);
            third_array[index_counter_3] = temp;
            index_counter_3++;
        }
    }

    // GET FOURTH LINE'S NUMBERS TO ARRAY

    int index_counter_4 = 0;
    char *token4 = strtok(fourth_line, ":");
    while (token4 != NULL) {
        token4 = strtok(NULL, ",\n");
        if (token4 != NULL) {
            int temp = atoi(token4);
            fourth_array[index_counter_4] = temp;
            index_counter_4++;
        }
    }

    //SORTING  & PRINTING FIRST **********************************

    for (int j = 0; j < index_counter_1; ++j) {
        for (int i = 0; i < index_counter_1; ++i) {
            int tmp = 0;
            if (first_array[j] < first_array[i]) {
                tmp = first_array[j];
                first_array[j] = first_array[i];
                first_array[i] = tmp;
            }
        }
    }

    for (int n = 0; n < index_counter_1; ++n) {
        printf("%d ", first_array[n]);
    }

    //*************************************************************

    printf("\n");

    //SORTING  & PRINTING SECOND **********************************

    for (int k = 0; k < index_counter_2; ++k) {
        for (int i = 0; i < index_counter_2; ++i) {
            int tmp = 0;
            if (second_array[k] < second_array[i]) {
                tmp = second_array[k];
                second_array[k] = second_array[i];
                second_array[i] = tmp;
            }
        }
    }

    for (int i1 = 0; i1 < index_counter_2; ++i1) {
        printf("%d ", second_array[i1]);
    }

    //*************************************************************

    printf("\n");

    //SORTING  & PRINTING THIRD **********************************


    for (int l = 0; l < index_counter_3; ++l) {
        for (int i = 0; i < index_counter_3; ++i) {
            int tmp = 0;
            if (third_array[l] < third_array[i]) {
                tmp = third_array[l];
                third_array[l] = third_array[i];
                third_array[i] = tmp;
            }
        }
    }

    for (int j1 = 0; j1 < index_counter_3; ++j1) {
        printf("%d ", third_array[j1]);
    }

    //*************************************************************

    printf("\n");


    //SORTING  & PRINTING FOURTH ********************************


    for (int m = 0; m < index_counter_4; ++m) {
        for (int i = 0; i < index_counter_4; ++i) {
            int tmp = 0;
            if (fourth_array[m] < fourth_array[i]) {
                tmp = fourth_array[m];
                fourth_array[m] = fourth_array[i];
                fourth_array[i] = tmp;
            }
        }
    }
    for (int k1 = 0; k1 < index_counter_4; ++k1) {
        printf("%d ", fourth_array[k1]);
    }
    //*************************************************************

    // GETTING MEDIAN OF ARRAYS

    float first_array_median = 0;
    int size_of_first = sizeof(first_array)/ sizeof(first_array[0]);

    if (size_of_first % 2 == 0) {
        first_array_median = (first_array[(size_of_first - 1) / 2] + first_array[size_of_first / 2]) / 2.0;
    } else {
        first_array_median = first_array[size_of_first / 2];
    }
    printf("\n %.2f", first_array_median);

    //*************************************************************

    float second_array_median = 0;
    int size_of_second = sizeof(second_array)/ sizeof(second_array[0]);

    if (size_of_second % 2 == 0) {
        second_array_median = (second_array[(size_of_second - 1) / 2] + second_array[size_of_second / 2]) / 2.0;
    } else {
        second_array_median = second_array[size_of_second / 2];
    }
    printf("\n %.2f", second_array_median);

    //*************************************************************

    float third_array_median = 0;
    int size_of_third = sizeof(third_array)/ sizeof(third_array[0]);

    if (size_of_third % 2 == 0) {
        third_array_median = (third_array[(size_of_third - 1) / 2] + third_array[size_of_third / 2]) / 2.0;
    } else {
        third_array_median = third_array[size_of_third / 2];
    }
    printf("\n %.2f", third_array_median);

    //*************************************************************

    float fourth_array_median = 0;
    int size_of_fourth = sizeof(fourth_array)/ sizeof(fourth_array[0]);

    if (size_of_fourth % 2 == 0) {
        fourth_array_median = (fourth_array[(size_of_fourth - 1) / 2] + fourth_array[size_of_fourth / 2]) / 2.0;
    } else {
        fourth_array_median = fourth_array[size_of_fourth / 2];
    }
    printf("\n %.2f", fourth_array_median);

    printf("\n\n The lowest median is the 4th array's median, which is %.2f.", fourth_array_median);
}

int main()
{

    lowest_median("../input.txt");

    return 0;
}