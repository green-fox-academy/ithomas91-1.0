#include <iostream>
#include <string>

 // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element


// Test for Functions


int terulet(int a);
int kerulet(int a);

int main(int argc, char* args[]) {


    // Számolja ki a kocka kerületét és területét!
    // a = userinput

    int a;

    std::cout<< "Adja meg a kocka egy oldalát cm-ben!"<<std::endl;
    std::cin>> a;

    std::cout<<"A kocka területe: "<< terulet(a) <<" cm és kerülete: "<< kerulet(a)<<" cm."<<std::endl;





    return 0;
}

int terulet(int a){

    int t = a * a;

    return t;

}

int kerulet(int a){

    int k = 4 * a;

    return k;

}