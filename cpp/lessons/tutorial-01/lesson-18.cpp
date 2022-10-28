#include <iostream>

using namespace std;

int main() {

    int n;
    unsigned long anterior = 0;
    unsigned long atual = 1;
    unsigned long proximo;

    cout << "Quantos numeros de fibonacci quer? ";
    cin >> n;

    // 0, 1, 1, 2, proximo = (anterior + atual),

    for (int i = 0; i < n; i++) {
        //cout << atual << ", "; 
        cout << "atual = " << atual << "\n"; 
        
        proximo = anterior + atual;
        cout << "proximo =" << anterior << "+" << atual << "=" << proximo << "\n"; 
        
        anterior = atual;
        cout << "anterior = " << anterior << "\n"; 

        atual = proximo;
        cout << "atual = " << proximo << "\n\n"; 
    }

    cout << "\n";  

    return 0;
}