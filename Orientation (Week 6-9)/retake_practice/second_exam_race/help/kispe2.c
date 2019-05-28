#include "race.h"

char *get_category(category_t type){
   switch(type) {
       case HANDICAPPED : return "Handicapped";
       case AMATEUR: return "Amateur";
       case PROFESSIONAL : return "Professional";
   }
}

void get_winner(competitor_t *competitors, unsigned int number_of_competitors, category_t type)
{
   unsigned int winner_number = 0;
   unsigned int winner_time = 5500;
   for (int i = 0; i < number_of_competitors; ++i) {
       if(competitors[i].finish_time <= winner_time && competitors[i].category == type) {
           winner_time = competitors[i].finish_time;
           winner_number = competitors[i].start_number;
       }
   }
   printf("Start number of %s category winner is %d and the winning time is %d seconds\n", get_category(type), winner_number, winner_time);
}