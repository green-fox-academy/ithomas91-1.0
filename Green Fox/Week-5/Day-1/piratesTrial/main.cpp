#include <iostream>
#include <vector>
#include "pirate.h"
#include "ship.h"

int main()
{
    Pirate pirate1("Jack Sparrow", true, false);
    Pirate pirate2("Captain Hook", true, true);
    Pirate pirate3("Blackburn 'Weasel' Lore", false, true);

    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;

    Ship ship;
    ship.addPirate(pirate1);
    ship.addPirate(pirate2);
    ship.addPirate(pirate3);

    ship.prepareForBattle();
    ship.lastDayOnTheShip();

    std::cout << "The names of the poor pirates are: " << std::endl;
    std::vector<std::string> poorPirateNames = ship.getPoorPirates();
    for (int i = 0; i < poorPirateNames.size(); ++i) {
        std::cout << "\t" << poorPirateNames[i] << std::endl;
    }

    std::cout << "The total amount of gold on the ship is " <<ship.getGolds() << std::endl;

    return 0;
}