#include <iostream>

using namespace std;

int main() {

    int Vetor1[4];
    Vetor1[0] = 1;
    Vetor1[1] = 2;
    Vetor1[2] = 3;
    Vetor1[3] = 4;

    int Vetor2[4] = {5, 10}; // restantes elementos ficam com 0 {5, 10, 0, 0};

    int Vetor3[] = {5, 10};    

    for (int i : Vetor3) {
        cout << i << endl;
    }

    int x = sizeof(Vetor3); // qt bytes
    int y = sizeof(Vetor3)/sizeof(int); // qt elementos
    cout << x << " bytes " << y << " elementos "<< endl;

    
    return 0;
}