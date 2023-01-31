#include <iostream>

using namespace std;


string fazer_cafe(bool acucar = false, bool leite = false) {

    if (!acucar && !leite) {
        return "Cafe simples";
    }

    else if (acucar && !leite) {
        return "Cafe com acucar";
    } 

    else if (leite && !acucar) {
        return "Pingo";
    } 

    return "Pingo doce";
}

int main() {

    cout << fazer_cafe() << endl;
    cout << fazer_cafe(true) << endl;
    cout << fazer_cafe(false, true) << endl;
    cout << fazer_cafe(true, true) << endl;

    return 0;
}