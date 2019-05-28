//
// Created by Tamas Nemeth on 2019-02-12.
//

#include <vector>
#include "carrier.h"

Carrier::Carrier(std::vector<Aircraft *> carrierVector, int ammoStore, int healthPoint)
{
    _carrierVector = carrierVector;
    _ammoStore = ammoStore;
    _healthPoint = healthPoint;
}
void Carrier::add(Aircraft *aircraft)
{
    _carrierVector.push_back(aircraft);
}
void Carrier::fill()
{
    for (int i = 0; i < _carrierVector.size(); ++i) {
        _necessaryAmmoAmount += _carrierVector[i]->getNecessaryAmmo();
    }
    for (int i = 0; i < _carrierVector.size(); ++i) {
        if (_ammoStore >= _necessaryAmmoAmount) {

            _ammoStore = _carrierVector[i]->refill(_ammoStore);

        } else if (_ammoStore < _necessaryAmmoAmount && _carrierVector[i]->isPriority()
        && _carrierVector[i]->getAmmo() < _carrierVector[i]->getMaxAmmo()
        && _ammoStore > 0) {

                _ammoStore = _carrierVector[i]->refill(_ammoStore);
        }
    }

    for (int j = 0; j < _carrierVector.size(); ++j) {
        if (_ammoStore > 0 && _carrierVector[j]->getAmmo() != _carrierVector[j]->getMaxAmmo()) {
            _ammoStore = _carrierVector[j]->refill(_ammoStore);
        } else {
            throw "The ammo store of the carrier is empty!";
        }
    }
}
void Carrier::fight(Carrier &carrier1)
{
    for (int i = 0; i < _carrierVector.size(); ++i) {
        _allDamage += _carrierVector[i]->fight();
    }
    for (int j = 0; j < carrier1._carrierVector.size(); ++j) {
        carrier1._allDamage += carrier1._carrierVector[j]->fight();
    }
    if(_healthPoint <= carrier1._allDamage){
        _healthPoint = 0;
    } else {
        _healthPoint - carrier1._allDamage;
    }
    if(carrier1._healthPoint <= _allDamage){
        carrier1._healthPoint = 0;
    } else {
        carrier1._healthPoint - _allDamage;
    }
}
std::string Carrier::getStatus()
{
    if(_healthPoint == 0){
        return "It's dead Jim :(";
    } else {
        std::string allAircrafts;
        for (int i = 0; i < _carrierVector.size(); ++i) {
           return allAircrafts += _carrierVector[i]->getStatus();
        }

        return "HP:" + std::to_string(_healthPoint) + ", Aircraft count: " + std::to_string(_carrierVector.size()) +
            ", Ammo Storage: " + std::to_string(_ammoStore) + " , Total damage: " + std::to_string(_allDamage) + "\n" +
            "Aircrafts: " + " \n " + allAircrafts;
    }
}
