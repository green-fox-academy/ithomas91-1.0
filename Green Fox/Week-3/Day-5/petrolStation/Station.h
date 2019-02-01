//
// Created by Tamas Nemeth on 2019-02-01.
//

#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H
#include "Car.h"


class Station {
public:
    Station(int gasAmountStation);
    void fill(Car &carname);


private:

    int gasAmountStation;
};


#endif //PETROLSTATION_STATION_H
