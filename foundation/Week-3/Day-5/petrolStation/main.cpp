#include <iostream>
#include "Car.h"
#include "Station.h"

int main() {



    Station shell = Station(1000);
    Car audi = Car(80, 100);


    for (int i = 0; i < 100; ++i) {
        shell.fill(audi);
    }


    return 0;
}