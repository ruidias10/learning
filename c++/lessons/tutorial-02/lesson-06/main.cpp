#include <iostream>
#include "car/car.h"

using namespace std;

int main() {
    
    car seat ("Seat", 100.00);
    car vw ("Volkswagen", 150.00);
    
    cout << seat.getbrand() << " " << seat.getkms() << " km" << endl;
    cout << vw.getbrand() << " " << vw.getkms() << " km" << endl;

    return 0;
}