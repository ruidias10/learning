#include <iostream>

using namespace std;

// 0x: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  A,  B,  C,  D,  E,  F
// 10: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

class Pessoa {
    public:
        int idade;
        string nome;

        Pessoa(string nome_, int idade_) : nome(nome_), idade(idade_) {

        }
};



int main() {

    Pessoa* p1 = new Pessoa("João", 22);
    Pessoa* p2 = new Pessoa("Manuel", 27);
    Pessoa* p3 = new Pessoa("Maria", 30);
    Pessoa* p4 = new Pessoa("Diana", 35);

    // Primeiro ministro
    Pessoa* pm = nullptr;

    cout << "PM: " << pm << endl;

    pm = p4;
    cout << "PM: " << pm->nome << endl;
    cout << "PM: " << pm << " " << p4 << endl;

    pm = p1;
    cout << "PM: " << pm->nome << endl;    
    cout << "PM: " << pm << " " << p1 << endl;


    cout << endl;

    return 0;
}