#include <iostream>
#include <string>

// - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

int main(int argc, char* args[]) {

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

    int sump1 = sizeof(p1) / sizeof(p1[3]);
    int sump2 = sizeof(p2) / sizeof(p2[2]);

    if (p2 > p1){

        std::cout<<"P2 is bigger array than P1"<<std::endl;

    }
    else {

        std::cout<<"P1 is bigger array than P2"<<std::endl;
    }





    return 0;
}
