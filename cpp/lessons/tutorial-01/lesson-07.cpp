#include <iostream>

using namespace std;

int main() {

    int escala = 0;
    string userinput = "";

    
    while (escala < 1 || escala > 10) {
        cout << "Indique um valor entre 1 e 10: ";
        
        try {
            cin >> userinput;
            escala = stoi(userinput);
        } catch (exception &err) {
            cout << "Tem de inserir um numero!!!" << endl;
        }
    }
    
    switch (escala) {
        case 1:
            cout << "Talco" << endl;
            break;
        case 2:
            cout << "Gesso" << endl;
            break;
        case 3:
            cout << "Calcite" << endl;
            break;
        case 4:
            cout << "Fluorite" << endl;
            break;
        case 5:
            cout << "Apatite" << endl;
            break;
        case 6:
            cout << "Feldspato" << endl;
            break;
        case 7:
            cout << "Quartzo" << endl;
            break;
        case 8:
            cout << "Topazio" << endl;
            break;
        case 9:
            cout << "Corindo" << endl;
            break;
        case 10:
            cout << "Diamante" << endl;
            break;                        
    }

    return 0;
}