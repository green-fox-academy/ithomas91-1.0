#include <stdio.h>
#include <string.h>
#include "car.h"

int get_older_cars_than(struct car *array, int array_lenght, int age)
{
    int counter = 0;
    for (int i = 0; i < array_lenght; ++i) {
        if (array[i].year_ofManufacture < age) {
            counter++;
        }
    }
    return counter;

}
int get_transmission_count(struct car *array, int array_lenght, enum transmission trnsm)
{
    int trsm_counter = 0;
    for (int i = 0; i < array_lenght; ++i) {
        if (array[i].transmission == trnsm) {
            trsm_counter = 0;
        }
    }
}

int main()
{
    car_t car1;
    strcpy(car1.manufacturer, "Audi");
    car1.price = 3200;
    car1.year_ofManufacture = 2006;
    car1.transmission = MANUAL;

    car_t car2;
    strcpy(car2.manufacturer, "Toyota");
    car2.price = 2800;
    car2.year_ofManufacture = 2007;
    car2.transmission = MANUAL;

    car_t car3;
    strcpy(car3.manufacturer, "VW");
    car3.price = 5000;
    car3.year_ofManufacture = 2015;
    car3.transmission = AUTOMATIC;

    car_t car_array[3] = {car1, car2, car3};

    int age_of_car = 2008;

    printf("What is the maximum of the year of manufacture of the car, what you looking for?\n");

    int number_of_fit = get_older_cars_than(car_array, 3, age_of_car);

    printf("We have %d car(s) for you than\n", number_of_fit);

    printf("The following cars are fit to your thoughts: \n");

    get_transmission_name(MANUAL);
    get_transmission_name(AUTOMATIC);

    int transmission_automatic = get_transmission_count(car_array, 3, AUTOMATIC);
    printf("There is/are %d automatic transmission car in the garage!\n", get_transmission_count(car_array, 3, AUTOMATIC));

    int transmission_manual = get_transmission_count(car_array, 3, MANUAL);
    printf("There is/are %d manual transmission car in the garage!\n", transmission_manual);

    for (int i = 0; i < 3; ++i) {
        printf("%s \t %d \t %f \t %s", car_array[i].manufacturer, car_array[i].price, car_array[i].year_ofManufacture,
            car_array[i].transmission );
    }


    return 0;
}