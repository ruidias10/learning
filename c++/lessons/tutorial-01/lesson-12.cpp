#include <iostream>

using namespace std;


int main() {

    int num = -1;

    while (num < 0) {
        cout << "Indique um numero inteiro positivo: ";
        cin >> num;
    }    

    for (int i = 0; i <= num; i++) {
        cout << i << "x" << i << "=" << i * i << "\n";
    }

    cout << "\n";
    
    return 0;
}    