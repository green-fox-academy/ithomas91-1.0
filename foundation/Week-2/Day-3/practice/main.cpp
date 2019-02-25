#include <iostream>
#include <string>

using namespace std;


// - Create (dynamically) a two dimensional array
//   with the following matrix. Use a loop!
//   by dynamically, we mean here that you can change the size of the matrix
//   by changing an input value or a parameter or this combined
//
//   1 0 0 0
//   0 1 0 0
//   0 0 1 0
//   0 0 0 1
//
// - Print this two dimensional array to the output

int main(int argc, char* args[]) {

    int a[4][4]
    {
        { 1, 0, 0, 0},
        { 0, 1, 0, 0},
        { 0, 0, 1, 0},
        { 0, 0, 0, 1}
    };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
           //cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j]<<" ";
            if(j == 3)
                cout << ""<< endl;
        }
    }
    string f;
cin>> f;
    return 0;
}