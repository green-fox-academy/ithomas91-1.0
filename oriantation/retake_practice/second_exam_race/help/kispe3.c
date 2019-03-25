#ifndef RACE_RACE_H
#define RACE_RACE_H

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef enum{
   HANDICAPPED,
   AMATEUR,
   PROFESSIONAL
} category_t;

typedef struct competitor {
   unsigned int start_number;
   category_t category;
   unsigned int finish_time;
} competitor_t;

void get_winner(competitor_t *competitors, unsigned int number_of_competitors, category_t type);
char *get_category(category_t type);

#endif //RACE_RACE_H