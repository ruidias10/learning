#include <iostream>

using namespace std;

// 0x: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  A,  B,  C,  D,  E,  F
// 10: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

void potencia1(int x) {
    cout << x * x << endl;

    x = x * x;
}

void potencia2(int& x) {
    cout << x * x << endl;

    x = x * x;
}


int main() {
    int x = 7;

    potencia1(x);
    cout << "X: " << x << endl;

    potencia2(x);
    cout << "X: " << x << endl;


    cout << endl;

    return 0;
}