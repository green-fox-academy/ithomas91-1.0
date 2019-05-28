#include <stdio.h>

float

int main()
{

    int N; // numbers of classes took the exam
    int M; // numbers of students took the exam in the 1st class
    float results [M];
    char name_of_class[20];
    int student_counter = 0;


    printf("How many classes took the exam?\n");
    scanf("%d", N);

    printf("\nHow many students took the exam in the first class?\n");
    scanf("%d", M);

    printf("\n What is the name of the class?\n ");
    scanf("%s", name_of_class);


    printf("What are the results one by one in persentage?\n");


    for (int i = 0; i < M; ++i) {
        scanf("%f", results);
    }

    return 0;
}