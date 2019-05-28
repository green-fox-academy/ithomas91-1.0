//
// Created by Tamas Nemeth on 2019-02-01.
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class Car {
public:

    Car(int _gasAmountCar, int _carGasCapacity);
    bool isFull();
    int fill();

private:

    int gasAmountCar;
    int carGasCapacity;
    bool full;

};


#endif //PETROLSTATION_CAR_H
