#include "race.c"

int main() {
   srand(time(0));
   unsigned int number_of_competiors = rand() % 1000 + 500;

   competitor_t *racers = (competitor_t*)calloc(number_of_competiors, sizeof(competitor_t));
   for (int i = 0; i < number_of_competiors; ++i) {
       racers[i].start_number = (unsigned int) i + 1;
       racers[i].category = rand() % 3;
       racers[i].finish_time = (unsigned int) rand() % 5500 + 3300;
   }

   get_winner(racers, number_of_competiors, HANDICAPPED);
   get_winner(racers, number_of_competiors, AMATEUR);
   get_winner(racers, number_of_competiors, PROFESSIONAL);

   return 0;
}


