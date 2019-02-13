#include <iostream>
#include "aircraft.h"
#include "f16.h"
#include "f35.h"
#include "carrier.h"

int main()
{
    std::vector <Aircraft *> blackPerl;

    F16 kisPe;
    F16 Tamas;

    F35 nagyPe;
    F35 nagyTomi;

    blackPerl.push_back(&kisPe);
    blackPerl.push_back(&Tamas);
    blackPerl.push_back(&nagyPe);
    blackPerl.push_back(&nagyTomi);

    Carrier blackPeach(blackPerl, 100, 900);

    std::vector <Aircraft*> whiteRaven;

    F16 kisPe2;
    F16 Tamas2;

    F35 nagyPe2;
    F35 nagyTomi2;

    blackPerl.push_back(&kisPe2);
    blackPerl.push_back(&Tamas2);
    blackPerl.push_back(&nagyPe2);
    blackPerl.push_back(&nagyTomi2);

    Carrier whitePeach(whiteRaven, 200, 50);

    blackPeach.fight(whitePeach);

    std::cout << blackPeach.getStatus() << std::endl;
    std::cout << whitePeach.getStatus();

    return 0;
}