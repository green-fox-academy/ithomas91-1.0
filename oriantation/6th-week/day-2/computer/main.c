#include <stdio.h>
#include <stdint.h>
#include <memory.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer
{
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
};

typedef struct
{
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
} Notebook_t;

int main()
{
    struct Computer computer;
    computer.cpu_speed_GHz = 2.5;
    computer.ram_size_GB = 8;
    computer.bits = 64;

    printf("This Apple MacBook Pro has %.2f GHz CPU, %d GB RAM, and it has %d BITS\n",
           computer.cpu_speed_GHz, computer.ram_size_GB, computer.bits);

    Notebook_t notebook;
    notebook.cpu_speed_GHz = 3.5;
    notebook.ram_size_GB = 16;
    notebook.bits = 64;

    printf("This notebook has %.2f GHz CPU, %d GB RAM, and it has %d BITS",
           notebook.cpu_speed_GHz, notebook.ram_size_GB, notebook.bits);
    return 0;
}