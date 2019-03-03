#include <stdio.h>

int main()
{
    FILE * f_pointer;
    f_pointer = fopen("testfileIO-txt", "w");

    fprintf(f_pointer, "I love english football \n i am watching everton - liverpool derby now.\n The result at the moment 0-0\n");

    fclose(f_pointer);

    FILE *fPointer;
    fPointer = fopen("testfileIO-txt", "r");

    char stringLine[150];

    while(!feof(fPointer)){
        fgets(stringLine, 150, fPointer);
        puts(stringLine);
    }

    fclose(fPointer);

    FILE * f_Pointer;
    f_Pointer = fopen("testfileIO-txt", "a");

    fprintf(f_Pointer, "However Liverpool has got may chance, its still 0-0 at the 72th min");

    fclose(f_Pointer);

}