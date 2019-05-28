#include <iostream>
#include <vector>

#include "Dominos.h"

std::vector<Domino> initializeDominoes() {
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}
int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();


    for (int j = 0; j < dominoes.size()-1; ++j) {

        for (int i = j; i < dominoes.size()-1; ++i) {

            Domino help;

            if (dominoes[j].getValues().second == dominoes[i+1].getValues().first) {
                help = dominoes[j + 1];
                dominoes[j + 1] = dominoes[i];
                dominoes[i] = help;

                        std::cout << dominoes[j] << std::endl;
            }
        }
    }
    return 0;
}






// You have the list of Dominoes
// Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
// eg: [2, 4], [4, 3], [3, 5] ...