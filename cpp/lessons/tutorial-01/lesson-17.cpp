#include <iostream>

using namespace std;

int main() {

    int list[5];
    //int list[] = {1, 2, 3, 4, 5};
    //int list[5] = {1, 2, 3, 4, 5};
    int size = sizeof(list) / sizeof(int);

    for (int i = 0; i < size; i++) {
        cout << "Indique o numero " << (i+1) << ": ";
        cin >> list[i];
    }    

    cout << "Os numeros escolidos foram: " << endl;
    for (int i = 0; i < size; i++) {
       cout << list[i] << " x " << i << " = " << list[i] * i << endl;
    }    

    cout << "\n";    

    return 0;
}