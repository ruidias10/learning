#include <iostream>

using namespace std;

int main() {

    int limit;

    cout << "Indique um numero positivo: ";
    
    cin >> limit;

    for (int i = 0; i <= limit; i++) {
        int k = i+1;
        cout << k << "^" << k << " = "<< k*k << endl;
    }

    cout << "\n";
    return 0;
}