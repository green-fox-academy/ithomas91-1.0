//
// Created by Tamas Nemeth on 2019-02-01.
//

#include "Station.h"
#include "Car.h"
#include <string>
#include <iostream>

Station::Station(int _gasAmountStation) {

    gasAmountStation = _gasAmountStation;

}

void Station::fill(Car &carname) {
    if (!carname.isFull()) {
        carname.fill();
        std::cout << "Filling Car..." << std::endl;
        gasAmountStation--;


    } else {

        std::cout << "\nTank is full! \nRemaining gas in the station : " << gasAmountStation << std::endl;

}