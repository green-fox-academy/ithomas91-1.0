#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2D.h"
#include "printer3D.h"
#include "copier.h"


int main() {


    Printer2D printer1(2, 4);
    Printer2D printer2(4, 8);
    Printer2D printer3(8, 16);

    Printer3D printer4(2, 4, 6);
    Printer3D printer5(8, 10, 12);

    Copier copier1(4, 6, 100);

    std::vector<Printer*> vectorPrinters;
    vectorPrinters.push_back(&printer1);
    vectorPrinters.push_back(&printer2);
    vectorPrinters.push_back(&printer3);
    vectorPrinters.push_back(&printer4);
    vectorPrinters.push_back(&printer5);
    vectorPrinters.push_back(&copier1);

    for (int i = 0; i < vectorPrinters.size(); ++i) {
         vectorPrinters[i]->Print();
    }

    std::vector<Scanner*> vectorScanner;

    Scanner scanner1(100);
    Scanner scanner2(200);

    Copier copy1(2, 4, 100);
    Copier copy2(6, 8, 200);

    vectorScanner.push_back(&scanner1);
    vectorScanner.push_back(&scanner2);

    vectorScanner.push_back(&copy1);
    vectorScanner.push_back(&copy2);

    for (int j = 0; j < vectorScanner.size(); ++j) {
        vectorScanner[j]->Scan();
    }

    copy2.copy();

    return 0;
}