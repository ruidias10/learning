#include <iostream>

using namespace std;

// 0x: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  A,  B,  C,  D,  E,  F
// 10: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

int main() {

    int a[4] = {1, 2, 3, 4};

    cout << "a: " << a << endl; // endereco de memoria

    cout << "*a+0: " << *(a+0) << " " << (&a+0) << endl; 
    cout << "*a+1: " << *(a+1) << " " << (&a+1) << endl; 
    cout << "*a+2: " << *(a+2) << " " << (&a+2) << endl; 
    cout << "*a+3: " << *(a+3) << " " << (&a+3) << endl; 


    cout << endl;

    return 0;
}