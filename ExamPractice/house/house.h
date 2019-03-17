//
// Created by Tamas Nemeth on 2019-03-17.
//

#ifndef UNTITLED_HOUSE_H
#define UNTITLED_HOUSE_H


typedef struct house
{
  char *address;
  int price_in_EURO;
  int number_of_rooms;
  int area_sm;
} house_t;

house_t create_house(char *_address, int _price, int _rooms, int _area_sm)
{
    house_t house;
    house.address = _address;
    house.price_in_EURO = _price;
    house.number_of_rooms = _rooms;
    house.area_sm= _area_sm;
    return house;
}

int worth_to_buy(house_t *house){
    if(house->price_in_EURO <= (400 * house->area_sm)){
        return 1;
    } else {
        return 0;
    }
}

int counting_houses_worth_to_buy(house_t array[], int lenght_array){
    int counter = 0;
    for (int i = 0; i < lenght_array; ++i) {
        if(worth_to_buy(&array[i])){
            counter++;
        }
    }
    return counter;
}

#endif //UNTITLED_HOUSE_H
