#include <iostream>

using namespace std;

int soma(int num1, int num2 = 5) {
    return num1 + num2;
}

float soma(float num1, float num2) {
    return num1 + num2;
}

int main() {

    cout << "Soma: int " << soma(10) << endl;
    cout << "Soma: int " << soma(10, 20) << endl;

    cout << "Soma: float " << soma(10.3f, 20.2f) << endl;

    return 0;
}