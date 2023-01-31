#include <iostream>

using namespace std;

int main() {

    int* Vetor1 = new int[10];
    Vetor1[0] = 1;
    Vetor1[1] = 2;
    Vetor1[2] = 3;

    delete [] Vetor1;
    
    return 0;
}