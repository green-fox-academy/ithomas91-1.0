#include <stdio.h>
#include <memory.h>

int count_yeah(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if(file_pointer == NULL){
        printf("File cannot be opened!!");
        return -1;
    }

    char *yeah = "yeah";
    unsigned int line_counter = 0;
    char *file_buffer;

    while(!feof(file_pointer)){
    fgets(file_buffer, 100, file_pointer);
       // printf("%s", file_buffer);
        char *token = strtok(file_buffer, " ");
        while (token != NULL){

            token = strtok(NULL, "\n");
            printf("%s", token);
        }

    }
    return line_counter;
}


int main()
{

    count_yeah("../input.txt");

    return 0;
}