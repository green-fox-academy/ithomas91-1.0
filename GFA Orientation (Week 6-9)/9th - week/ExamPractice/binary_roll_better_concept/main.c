#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


char *binary_to_ascii(char * input_char)
{
    char result = 0;
    int lenght = strlen(input_char);

    for (int i = 0; i < lenght; ++i) {
        char c = input_char[i];
        if (c == '1'){
            int power = lenght - 1 -i;
            result += (1 << power);
        }
    }
    return result;
}


char *convert_binary_text(char *file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL){
        printf("File hasn't been opened!!!");
        return NULL;
    }

    char *result_string = (char*)malloc(sizeof(char));
    int i_counter = 0;

    char buffer_string[10];
    while(fgets(buffer_string, 10, file_pointer) != NULL){
        buffer_string[8] = '\0';
        char result = binary_to_ascii(buffer_string);
        result_string[i_counter] = result;
        i_counter++;
        result_string = (char*)realloc(result_string, (i_counter + 1) * sizeof(char));
    }
    result_string[i_counter] = '\0';

    fclose(file_pointer);

    return result_string;
}

int main()
{
   /* TESTING*******************************
    char my_char[] = "01010111";
    char *result = binary_to_ascii(my_char);
    printf("%s", &result);
    *****************************************/

   char *text = convert_binary_text("../input.txt");
   printf("%s", text);

   free(text);
    return 0;
}