#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/


typedef struct house
{
  char *_address;
  int _price_in_euro;
  int _number_of_rooms;
  int _area_in_square_meters;
} house_t;

house_t create_house(char *address, int price, int number_of_rooms, int area)
{
    house_t my_house;
    my_house._address = address;
    my_house._price_in_euro = price;
    my_house._number_of_rooms = number_of_rooms;
    my_house._area_in_square_meters = area;
    return my_house;
}

int worth_to_buy(house_t *house)
{
    int result = 0;
    if (house->_price_in_euro / house->_area_in_square_meters < 400) {
        result = 1;
        return result;
    }
}

void houses_worth_to_buy(house_t *array, int lenght)
{
    int counter = 0;
    for (int i = 0; i < sizeof(array); ++i) {
        if (worth_to_buy(&array[i]) == 1) {
            counter++;
            printf("%d . house is worth to buy!\n", counter);
        }
    }
    printf("%d house worth to by from the array\n", counter);
}

int main()
{
    house_t house1 = create_house("33 Erzsebet srt", 40000, 2, 80);
    house_t house2 = create_house("7 Ifujsag srt", 100000, 4, 120);
    house_t house3 = create_house("20 Budai srt", 30000, 2, 60);
    house_t house4 = create_house("12 Szechenyi srt", 35000, 3, 80);

    printf("%d", (char) worth_to_buy(&house1));
    printf("%d", (char) worth_to_buy(&house2));
    printf("%d", (char) worth_to_buy(&house3));
    printf("%d", (char) worth_to_buy(&house4));

    house_t array_houses[4];
    int lenght_array = sizeof(array_houses) / sizeof(*array_houses);

    array_houses[0] = house1;
    array_houses[1] = house2;
    array_houses[2] = house3;
    array_houses[3] = house4;

    houses_worth_to_buy(array_houses, lenght_array);

    return 0;
}