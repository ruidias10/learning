#include <iostream>

using namespace std;

int main() {

    int limit;

    cout << "Indique um numero positivo: ";
    
    cin >> limit;

    for (int i = 0; i <= limit; i++) {
        cout << i << "^" << i << " = "<< i*i << endl;
    }

    cout << "\n";
    return 0;
}