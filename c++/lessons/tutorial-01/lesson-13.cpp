#include <iostream>

using namespace std;


int main() {

    int num, computer;

    while(true) {
        num = 0;
        computer = rand() % 11;

        while (num < 1 || num > 10) {
            cout << "Indique um numero entre 1 e 10: ";
            cin >> num;
        }    

        if (num == computer) {
            cout << " > Parabens! ["<< num <<" - " << computer << "] \n > Acertou no numero secreto...\n";
            break;
        }  else {
            cout << " > Ainda não foi desta! ["<< num <<" - " << computer << "] \n > Vamos tentar novamente...\n";
        }
    }
    
    return 0;
}    