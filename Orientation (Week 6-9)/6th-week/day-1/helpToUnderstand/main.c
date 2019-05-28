#include <stdio.h>
#include <string.h>

typedef struct team {
  char name[50];
  char main_technology[50];
  int number_of_members;
} team_t;

int main()
{
    team_t team;
    strcpy(team.name, "Jade-Selection");
    strcpy(team.main_technology, "Ruby-on-Rails");
    team.number_of_members = 5;

    printf("The team name is: %s , there are %d people working with %s.\n", team.name, team.number_of_members, team.main_technology);

    return 0;
}