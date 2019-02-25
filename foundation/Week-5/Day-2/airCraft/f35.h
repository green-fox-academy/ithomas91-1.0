//
// Created by Tamas Nemeth on 2019-02-12.
//

#ifndef AIRCRAFT_F35_H
#define AIRCRAFT_F35_H
#include "aircraft.h"


class F35 : public Aircraft
{
public:
  F35();
  int fight() override;
  int refill(int fillAmount) override;
  std::string getType() override;
  std::string getStatus() override;
  bool isPriority() override;
  int getAmmo()override;
  int getMaxAmmo()override;
  int getFilledAmmoAmount()override;
  int getNecessaryAmmo()override;


 protected:
  std::string _type = "F35";
  int _maxAmmo;
  int _baseDamage;
  int _ammoStore;
  int _filledAmmoAmount = 0;


};

#endif //AIRCRAFT_F35_H
