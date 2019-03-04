//
// Created by Tamas Nemeth on 2019-03-04.
//

#ifndef CARREGISTER_CAR_H
#define CARREGISTER_CAR_H

#endif //CARREGISTER_CAR_H

typedef enum transmission_type
{
  MANUAL,
  AUTOMATIC,
  CVT,
  SEMI_AMUTOMATIC,
  DUAL_CLUTCH
} transmission_type_t;

typedef struct car
{
  char manufacturers_name[256];
  float price_EUR;
  int year_of_manufacture;
  transmission_type_t transmission;
} car_t;

char *get_name_transmission(transmission_type_t transmission)
{
    switch (transmission) {
        case MANUAL : return "Manual";
        case AUTOMATIC : return "Automatic";
        case CVT : return "CVT";
        case SEMI_AMUTOMATIC : "Semi-Amutomatic";
        case DUAL_CLUTCH : "Dual-Clutch";
    }
}

int get_older_cars_than(struct car *array, int array_lenght, int age)
{
    int older_cars_counter = 0;
    for (int i = 0; i < array_lenght; ++i) {
        if (array[i].year_of_manufacture < age) {
            older_cars_counter++;
        }
    }
    return older_cars_counter;
}

int get_transmission_count(struct car *array, int array_lenght, transmission_type_t trnsm)
{
    int trnsm_counter = 0;
    for (int i = 0; i < array_lenght; ++i) {
        if(array[i].transmission==trnsm){
            trnsm_counter++;
        }
    }
}
