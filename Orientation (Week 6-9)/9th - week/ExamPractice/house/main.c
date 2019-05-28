#include <stdio.h>
#include "house.h"

int worth_to_buy(house_t *house);
int counting_houses_worth_to_buy(house_t array[], int lenght_array);

int main()
{

    house_t house1 = create_house("Ifjuság srt 7.", 50000, 4, 120);
    house_t house2 = create_house("Ifjuság srt 10.", 1000, 5, 100);
    house_t house3 = create_house("Ifjuság srt 1.", 2000, 4, 150);

    house_t array[3] = {house1, house2, house3};

    if (worth_to_buy(&house1) == 1) {
        printf("House 1 is worth to buy. \n");
    } else {
        printf("House 1 is not worth to buy.\n");
    }

    if (worth_to_buy(&house2) == 1) {
        printf("House 2 is worth to buy.\n");
    } else {
        printf("House 2 is not worth to buy.\n");
    }

    if (worth_to_buy(&house3) == 1) {
        printf("House 3 is worth to buy.\n");
    } else {
        printf("House 3 is not worth to buy.\n");
    }

    int lenght = sizeof(array) / sizeof(*array);
    printf("There are %d houses in the array.\n", lenght);

    printf("There is/are %d house/s int the array worth to buy!"
    , counting_houses_worth_to_buy(array, lenght));

    return 0;
}