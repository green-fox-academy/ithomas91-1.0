//
// Created by Tamas Nemeth on 2019-01-31.
//

#include "Counter.h"
Counter::Counter() {

    number = 0;
    x = userInput;

    Counter::add();

    Counter::get();

    Counter::reset();
}