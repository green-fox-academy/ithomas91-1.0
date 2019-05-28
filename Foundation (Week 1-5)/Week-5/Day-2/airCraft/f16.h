//
// Created by Tamas Nemeth on 2019-02-12.
//

#ifndef AIRCRAFT_F16_H
#define AIRCRAFT_F16_H
#include <string>
#include "aircraft.h"


class F16 : public Aircraft
{
 public:
    F16();
    int fight() override;
    int refill(int fillAmount) override;
    std::string getType() override;
    std::string getStatus() override;
    bool isPriority() override;
    int getNecessaryAmmo() override;
    int getAmmo()override;
    int getMaxAmmo()override;
    int getFilledAmmoAmount()override;



 protected:
    std::string _type = "F16";
    int _maxAmmo;
    int _baseDamage;
    int _ammoStore;
    int _filledAmmoAmount = 0;
};

#endif //AIRCRAFT_F16_H
