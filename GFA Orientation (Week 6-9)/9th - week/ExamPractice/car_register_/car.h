//
// Created by Németh Tamás on 2019-03-16.
//

#ifndef CAR_REGISTER_CAR_H
#define CAR_REGISTER_CAR_H

typedef enum transmission
{
  MANUAL,
  AUTOMATIC,
  CVT,
  SEMI_AUTOMATIC,
  DUAL_CLUTCH

} transmission_t;

typedef struct car
{
  char manufacturer[256];
  float price;
  int year_ofManufacture;
  transmission_t transmission;

} car_t;

const char* get_transmission_name(transmission_t transmission)
{
    switch (transmission)
    {
        case MANUAL: return "Manual";
        case AUTOMATIC: return "Automatic";
        case CVT: return "CVT";
        case SEMI_AUTOMATIC: return "Semi-automatic";
        case DUAL_CLUTCH: return "Dual Clutch";
    }
}

#endif //CAR_REGISTER_CAR_H
