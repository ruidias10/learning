#include <iostream>

using namespace std;


int main() {

    int num = 0;
    int tentativas = 5; 
    int computer = rand() % 11;

    do {
        num = 0;

        while (num < 1 || num > 10) {
            cout << "Indique um numero entre 1 e 10: ";
            cin >> num;
        }    

        tentativas--;  

        if (num == computer) {
            cout << " > Parabens! ["<< num <<" - " << computer << "] \n";
            cout << " > Acertou no numero secreto...\n";
            break;
        }  else {  
            cout << " > Ainda não foi desta! ["<< num <<" - " << computer << "] \n"; 
        }   

        if (tentativas == 0) {
            cout << " > Lamentamos, acabaram as tentativas...\n";
            break;
        } else {
            cout << " > Ainda temos " << tentativas << " tentativas...\n";
        }           

    } while(tentativas > 0);
    
    return 0;
}    