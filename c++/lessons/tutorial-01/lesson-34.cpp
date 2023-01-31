#include <iostream>

using namespace std;

// 0x: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  A,  B,  C,  D,  E,  F
// 10: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

int main() {
    int x = 27;

    int w = 42;

    int* y = &w; // aqui o y é um ponteiro
    y = &x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "w: " << w << endl;
    cout << "&w: " << &w << endl;

    cout << "y: " << y << endl;
    cout << "*y: " << *y << endl; // aqui usa o valor que está dentro do y
    cout << "&y: " << &y << endl;

    cout << "Soma: w+y=" << w + *y << endl;

    cout << endl;
    
    cout << "y: " << y << endl;
    cout << "y+1: " << y+1 << endl;
    cout << "*y: " << *y << endl;
    cout << "*y+1: " << *(y+1) << endl;


    cout << endl;

    return 0;
}