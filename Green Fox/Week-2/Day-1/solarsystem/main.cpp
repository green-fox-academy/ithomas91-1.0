#include <iostream>
#include <string>
#include <vector>

// Saturn is missing from the planetList
// Insert it into the correct position
// Create a method called putSaturn() which has list parameter and returns the correct list.

// Expected output: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune

std::vector<std::string> putSaturn(const std::vector<std::string>& planets)
{
    std::vector<std::string> newPlanet;

           for(int i = 0; i < planets.size(); i++){

               newPlanet.push_back(planets[i]);
           }

         newPlanet.insert(newPlanet.begin() + 5, "Saturn" );

           return newPlanet;
}

int main(int argc, char* args[])
{
    std::vector<std::string> planets = {"Mercury","Venus","Earth","Mars","Jupiter","Uranus","Neptune"};



    //int pos = planets.find("Jupiter");



     std::vector<std::string>correctPlanets = putSaturn(planets);
    for(int i = 0; i < correctPlanets.size(); ++i) {
        std::cout << correctPlanets[i] << " ";
    }

    return 0;
}