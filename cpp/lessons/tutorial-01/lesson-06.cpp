#include <iostream>

using namespace std;

int main() {    

    int ph;
    cout << "Indique o numero do PH: ";
    cin >> ph;

    if (ph < 7) {
        cout << "O PH " << ph << " e acido" << endl;
    } else if(ph > 7) {
        cout << "O PH " << ph << " e base" << endl;
    } else {
        cout << "O PH " << ph << " e neutro" << endl;
    }

    return 0;
}