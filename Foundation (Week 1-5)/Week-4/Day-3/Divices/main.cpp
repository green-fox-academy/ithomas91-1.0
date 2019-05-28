#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2D.h"
#include "printer3D.h"
#include "copier.h"
#include "scanner.h"

int main()
{
    std::vector<Printer*> myVector;

    Printer2D obj1(4, 5);
    Printer2D obj2(4, 6);
    Printer2D obj3(4, 7);

    Printer3D obj4(1, 2, 3);
    Printer3D obj5(2, 3, 5);

    Copier obj6(2, 5, 100);

    myVector.push_back(&obj1);
    myVector.push_back(&obj2);
    myVector.push_back(&obj3);

    myVector.push_back(&obj4);
    myVector.push_back(&obj5);

    myVector.push_back(&obj6);

    for(int i = 0; i < myVector.size(); i++){
        myVector[i]->print();
        //(*myVector[i]).print();
    }

    std::vector<Scanner*> myScanner;

    Scanner obj7(100);
    Scanner obj8(200);

    myScanner.push_back(&obj7);
    myScanner.push_back(&obj8);

    Copier obj9(1, 2, 300);
    Copier obj10(3, 4, 400);

    for (int j = 0; j < myScanner.size(); ++j) {
        myScanner[j]->scan();
    }

    Copier obj11(4, 5, 50);
    obj11.copy();

    return 0;
}