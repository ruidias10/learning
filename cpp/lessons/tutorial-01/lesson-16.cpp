#include <iostream>

using namespace std;


int main() {

    int list[5];
    int size = sizeof(list) / sizeof(int);

    for (int i = 0; i < size; i++) {
        cout << "Indique o numero " << (i+1) << ": ";
        cin >> list[i];
    }    

    cout << "Os numeros escolidos foram: ";
    for (int i = 0; i < size; i++) {
       cout << list[i] << " ";
    }    

    cout << "\n";    

    return 0;
}