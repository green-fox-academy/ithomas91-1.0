//
// Created by Tamas Nemeth on 2019-02-01.
//

#include "Car.h"

Car::Car(int _gasAmountCar, int _carGasCapacity) {

    gasAmountCar = _gasAmountCar;
    carGasCapacity = _carGasCapacity;
    full = false;



}

bool Car::isFull(){

    if(carGasCapacity == gasAmountCar){
        full = true;
    }
    return full;
}

int Car::fill(){

    gasAmountCar++;
}