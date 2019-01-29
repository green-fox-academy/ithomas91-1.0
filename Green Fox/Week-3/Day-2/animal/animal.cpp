//
// Created by Tamas Nemeth on 2019-01-29.
//

#include "animal.h"
#include <string>

animal::animal() {

     hunger = 50;
     thirst = 50;


}
void animal::eat(){
    hunger --;
}
void animal::drink(){
    thirst --;
}
void animal::play(){
    hunger ++;
    thirst ++;
}