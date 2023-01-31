#include <iostream>

using namespace std;

class Pessoa {
    public:
        int idade;
        string nome;

        Pessoa(string nome_, int idade_) : nome(nome_), idade(idade_) {

        }
};

void aniversario0(Pessoa p) {
    cout << "Idade inicial da " << p.nome << ": " << p.idade << endl;
    cout << "Idade: " << ++p.idade << endl; // atualiza e imprime
    cout << "Idade: " << p.idade++ << endl; // imprime e atualiza
}

void aniversario1(Pessoa& p) {
    cout << "Idade inicial da " << p.nome << ": " << p.idade << endl;
    cout << "Idade: " << ++p.idade << endl; // atualiza e imprime
    cout << "Idade: " << p.idade++ << endl; // imprime e atualiza
}

void aniversario2(Pessoa* p) {
    cout << "Idade inicial da " << p->nome << ": " << p->idade << endl;
    cout << "Idade: " << ++p->idade << endl; // atualiza e imprime
    cout << "Idade: " << p->idade++ << endl; // imprime e atualiza
}

int main() {

    Pessoa p0 = Pessoa("Silvia", 30);
    aniversario0(p0);
    cout << "Idade final da " << p0.nome << ": " << p0.idade << endl;
    cout << endl;


    Pessoa p1 = Pessoa("Maria", 30);
    aniversario1(p1);
    cout << "Idade final da " << p1.nome << ": " << p1.idade << endl;
    cout << endl;


    Pessoa* p2 = new Pessoa("Raquel", 30);
    aniversario2(p2);
    cout << "Idade final da " << p2->nome << ": " << p2->idade << endl;
    cout << endl;
    

    return 0;
}