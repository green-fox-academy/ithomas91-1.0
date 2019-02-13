//
// Created by Tamas Nemeth on 2019-02-12.
//

#ifndef AIRCRAFT_AIRCRAFT_H
#define AIRCRAFT_AIRCRAFT_H
#include <iostream>
#include <string>

class Aircraft
{
 public:
    virtual int fight() = 0;
    virtual int refill(int fillAmount) = 0;
    virtual std::string getType() = 0;
    virtual std::string getStatus() = 0;
    virtual bool isPriority() = 0;
    virtual int getNecessaryAmmo() = 0;
    virtual int getAmmo() = 0;
    virtual int getMaxAmmo() = 0;
    virtual int getFilledAmmoAmount() = 0;
 protected:
      int _maxAmmoF16 = 8;
      int _baseDamageF16 = 30;
      int _ammoStoreF16 = 0;
      int _maxAmmoF35 = 12;
      int _baseDamageF35 = 50;
      int _ammoStoreF35 = 0;
      int _necessaryAmmo;
};

#endif //AIRCRAFT_AIRCRAFT_H
