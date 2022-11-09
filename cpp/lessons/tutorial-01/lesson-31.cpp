#include <iostream>

using namespace std;


enum Cars { Mercedes = 400, BMW = 300, Audi = 200, Volkswagen = 100 };

int main() {

    Cars c1 = Audi;
    Cars c2 = Mercedes;

    cout << "c1: "<< c1 << endl;
    cout << "c2: "<< c2 << endl;

    cout << "c2: "<< 2/3 << endl;

    return 0;
}    