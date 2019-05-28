#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

competitor_t get_fastest();


int main()
{
    srand(time(0));
    unsigned int number_of_competitor = (unsigned int) rand() % 100 +1;

    competitor_t *racers = (competitor_t*)calloc(number_of_competitor, sizeof(competitor_t));
    for (int i = 0; i < number_of_competitor; ++i) {
        racers[i].start_number = (unsigned int) i + 1;
        racers[i].category = rand() % 3;
        racers[i].finish_time = (unsigned int) rand() % 5500 + 3000;
    }

    get_fastest(racers, number_of_competitor, HANDICAPPED);
    get_fastest(racers, number_of_competitor, AMATEUR);
    get_fastest(racers, number_of_competitor, PROFESSIONAL);

    return 0;
}