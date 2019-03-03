#include <stdio.h>

typedef struct {
  int age;
  int height;
  int weight;
} person_t;

typedef struct {
  int age : 2;
  int height : 2;
  int weight : 2;
} person_bitfield_t;

int main()
{
    printf("%d\n", sizeof(person_t)); // prints 12 (3 * 4 bytes)
    printf("%d\n", sizeof(person_bitfield_t)); // prints 4 (only one single byte)

    return 0;
}