//
// Created by Tamas Nemeth on 2019-02-12.
//

#include <iostream>
#include "f16.h"
#include "aircraft.h"

F16::F16() : Aircraft()
{
    _maxAmmo = _maxAmmoF16;
    _baseDamage = _baseDamageF16;
    _ammoStore = _ammoStoreF16;
}
int F16::fight()
{
    int tempAmmoStore;
    tempAmmoStore = _ammoStore;
    _ammoStore = 0;
    return tempAmmoStore * _baseDamage;

}
int F16::refill(int fillAmount)
{
    _filledAmmoAmount = _maxAmmo -_ammoStore;
    if(fillAmount <_filledAmmoAmount){
        _filledAmmoAmount = fillAmount;
        _ammoStore += fillAmount;
        return 0;
    } else {
        _ammoStore =_maxAmmo;
        return fillAmount - (_filledAmmoAmount);
    }
}
std::string F16::getType()
{
    return std::string(_type);
}
std::string F16::getStatus()
{
    return "Type" + _type + ", Ammo: " + std::to_string(_ammoStore) +
    ", Base Damage: " + std::to_string(_baseDamage) + ", All Damage: " +
    std::to_string(fight()) + "\n";
}
bool F16::isPriority()
{
    return false;
}
int F16::getNecessaryAmmo()
{
    return _maxAmmo - _ammoStore;
}
int F16::getAmmo()
{
    return _ammoStore;
}
int F16::getMaxAmmo()
{
    return _maxAmmo;
}
int F16::getFilledAmmoAmount()
{
    return _filledAmmoAmount;
}
