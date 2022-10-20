#include <iostream>

using namespace std;

int main() {

    int num1, num2;

    cout << "Indique o primeiro numero: ";
    cin >> num1;

    cout << "Indique o segundo numero: ";
    cin >> num2;

    cout << endl;

    if (num1 > -1 && num2 > -2) {
        cout << "2 - O numero " << num1 << " e o numero " << num2 << " sao positivos" << endl;
    }

    if (num1 < 0 && num2 < 0) {
        cout << "3 - O numero " << num1 << " e o numero " << num2 << " sao negativos" << endl;
    }    

    if (num1 == 0 && num2 == 0) {
        cout << "4 - O numero " << num1 << " e o numero " << num2 << " sao neutros" << endl;
    }

    if (!(num1 < 0 && num2 < 0)) {
        cout << "5 - O numero " << num1 << " e o numero " << num2 << " nao sao negativos" << endl;
    }

    if ((num1 < 0 && num2 < 0) || (num1 == 0 && num2 == 0)) {
        cout << "6 - O numero " << num1 << " e o numero " << num2 << " sao negativos os neutros" << endl;
    }
                    
    if (num1 > -1 && num1 < 11) {
        cout << "7 - O numero " << num1 << " esta entre 0 e 10" << endl;
    }

    if (num2 < 1 && num2 > -101) {
        cout << "8 - O numero " << num2 << " esta entre 0 e -100" << endl;
    }  

    return 0;
}