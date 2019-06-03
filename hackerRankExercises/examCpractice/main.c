#include <stdio.h>

void loopWhile()
{
    int answer = 4;
    int user_answer;
    int counter = 0;

    printf("Please enter your answer!\n");

    while(user_answer != answer){
        scanf("%d", &user_answer);
        counter++;
        if(counter == 3){
            printf("You havent got mor chance!\n");
            break;
        }
        printf("Wrong answer, try again!\n");

    }



    printf("User answer is : %d, correct answer is: %d", user_answer, answer);
}

void loopFor()
{
    int answer = 4;
    int user_answer;
    int counter = 3;

    printf("Please enter your answer!\n");

    for (int i = 0; i < 3; ++i) {
        scanf("%d", &user_answer);
        counter--;
        if(counter == 0) {
            printf("You DIED!\n");
            break;
        } else if (user_answer != answer){
            printf("Wrong answer, try again. You have %d more chance left\n", counter);

        } else {
            printf("Good job, you win!\n");
            break;
        }
    }
}

int decide_user_answer(char *answer)
{
    if(answer == "while"){
        return 0;
    } else if (answer == "for"){
        return 1;
    } else {
        printf("Wrong statement!\n");
        return -1;
    }
}

int main() {

    char *user_answer;
    printf("Enter the the type of the loop what i have to explain!\n");

    scanf("%s", user_answer);

    int result = decide_user_answer(user_answer);

    printf("%d", result);

    switch (result)
    {
        case 0 :
            loopWhile();
            break;
        case 1 :
            loopFor();
            break;
        default:
            printf("Error in the system!!\n");
            break;
    }

    return 0;
}