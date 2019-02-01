//
// Created by Tamas Nemeth on 2019-01-31.
//
#include <string>
#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
private:
    int number;
    int newNumber;

public:
    Counter();
    Counter(int result);
    float add();
    float add(float plusnumber);
    float get();
    void reset();

};


#endif //COUNTER_COUNTER_H
