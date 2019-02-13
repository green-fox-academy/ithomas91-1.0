//
// Created by Tamas Nemeth on 2019-02-12.
//

#ifndef AIRCRAFT_CARRIER_H
#define AIRCRAFT_CARRIER_H
#include "aircraft.h"
#include <vector>
#include <string>
#include <iostream>
class Carrier
{
 public:
  Carrier(std::vector<Aircraft*> carrierVector, int ammoStore, int healthPoint);
  void add(Aircraft *aircraft);
  void fill();
  void fight(Carrier &carrier1);
  std::string getStatus();
 private:
  std::vector<Aircraft*> _carrierVector;
  int _ammoStore;
  int _healthPoint;
  int _necessaryAmmoAmount;
  int _allDamage;

};

#endif //AIRCRAFT_CARRIER_H
