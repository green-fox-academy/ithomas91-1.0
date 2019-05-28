//
// Created by Tamas Nemeth on 2019-02-12.
//

#include <iostream>
#include "f35.h"

F35::F35() : Aircraft()
{
    _maxAmmo = _maxAmmoF35;
    _baseDamage = _baseDamageF35;
    _ammoStore = _ammoStoreF35;
}
int F35::fight()
{
    int tempAmmoStore;
    tempAmmoStore = _ammoStore;
    _ammoStore = 0;
    return tempAmmoStore * _baseDamage;
}
int F35::refill(int fillAmount)
{
    _filledAmmoAmount = _maxAmmo - _ammoStore;
    if (fillAmount < _filledAmmoAmount) {
        _filledAmmoAmount = fillAmount;
        _ammoStore += fillAmount;
        return 0;
    } else {
        _ammoStore = _maxAmmo;
        return fillAmount - (_filledAmmoAmount);
    }
}
std::string F35::getType()
{
    return std::string(_type);
}
std::string F35::getStatus()
{
    return "Type" + _type + ", Ammo: " + std::to_string(_ammoStore) +
        ", Base Damage: " + std::to_string(_baseDamage) + ", All Damage: " +
        std::to_string(fight()) + "\n";
}
bool F35::isPriority()
{
    return true;
}
int F35::getAmmo()
{
    return _ammoStore;
}
int F35::getMaxAmmo()
{
    return _maxAmmo;
}
int F35::getFilledAmmoAmount()
{
    return _filledAmmoAmount;
}
int F35::getNecessaryAmmo()
{
    return _necessaryAmmo;
}
