#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *name;
    unsigned int age;
    char *sex;
} person_t;

void csere(int *a,int *b);


int main() {

    //      M E M C P Y ( ) ;

    const char src[50] = "http://www.tutorialspoint.com";
    char dest[50];
    strcpy(dest,"Heloooo!!");
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);


    //      M E M S E T ( ) ;

    char string[20];
    strcpy(string, "Hello");
    printf( "Before using memset |%s|\n", string );
    memset( string, '\0', sizeof(string) );
    printf( "After using memset |%s|\n", string );


    //      S T R C A T ( ) ;

    char src1[50], dest1[50];
    strcpy(src1,  "This is source");
    strcpy(dest1, "This is destination");
    strcat(dest1, src1);
    printf("Final destination string : |%s|\n", dest1);


    //         S T R C M P ( ) ;

    char str1[15];
    char str2[15];
    int ret;
    strcpy(str1, "abcdef\n");
    strcpy(str2, "ABCDEf\n");
    printf("%d\n", str1);
    printf("%d\n", str2);
    ret = strcmp(str1, str2);
    if(ret < 0) {
        printf("str1 is less than str2\n");
    } else if(ret > 0) {
        printf("str2 is less than str1\n");
    } else {
        printf("str1 is equal to str2\n");
    }


    //         S T R S T R ( ) ;

    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "Point";
    char *retu;
    retu = strstr(haystack, needle);
    printf("The substring is: %s\n", retu);


    //      S T R T O K ( ) ;

    char str[80] = "This is - www.tutorialspoint.com - website";
    const char s[2] = " ";
    char *token;
    /* get the first token */
    token = strtok(str, s);
    /* walk through other tokens */
    while( token != NULL ) {
        printf( " %s\n", token );
        token = strtok(NULL, s);
    }

    char * movie = "Best";
    char movie2[] = "Best";

    printf("pointer: %d\n", sizeof(movie));
    printf("array: %d\n", sizeof(movie2));

    printf("-------------------------------------------------\n");

    char stringToken[80] = "My name is Tamas\n";
    char del[2] = " ";

    char *tokenize;
    tokenize = strtok(stringToken, del);
    while (tokenize != NULL){
        printf(" %s \t", tokenize);
        tokenize = strtok(NULL, del);
    }

    printf("----------------------------------------------\n");

        int k=2, l=4;

        printf("%d,%d",k,l);

        csere(&k,&l);

        printf("\n%d,%d \n",k,l);



        printf("-----------------------------------------------------\n");

        char soursString[50] = "i have an exam today.";
        char delString[2] = " ";

        char *ptr_token;
        ptr_token = strtok(soursString, delString);
        while(ptr_token != NULL){
            printf("%s \t", ptr_token);
            ptr_token = strtok(NULL, delString);
        }


        printf("\n------------------------------------------------------------\n");

        person_t person;

        person.name = "Tamas Nemeth";
        person.age = 28;
        person.sex = "Male";

        printf("So, this person is %s and he is %d old. His grender is %s . He would be really happy if he would pass"
               " tomorrow.\n", person.name, person.age, person.sex);


    return 0;
}

void csere(int *a,int *b)
{
    int s;
    s=*a;
    *a=*b;
    *b=s;
}
