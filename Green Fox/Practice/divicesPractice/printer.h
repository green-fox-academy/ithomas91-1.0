//
// Created by Németh Tamás on 2019-02-23.
//

#ifndef DIVICESPRACTICE_PRINTER_H
#define DIVICESPRACTICE_PRINTER_H


class Printer {
public:
    virtual std::string getSize() = 0;
    void Print();
protected:
};


#endif //DIVICESPRACTICE_PRINTER_H
