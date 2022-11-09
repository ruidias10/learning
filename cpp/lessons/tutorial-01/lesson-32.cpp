#include <iostream>
#include <vector>

using namespace std;

class Cancao {
    public:
        string nome;
        string artista;
        int anoGravacao;

        Cancao(string nome, string artista, int anoGravacao) {
            this->nome = nome;
            this->artista = artista;
            this->anoGravacao = anoGravacao;

            cout << "+ Construtor " << this->nome << endl; 
        }

        void print() {
            cout << "   > Nome: " << this->nome << endl; 
            cout << "   > Artista: " << this->artista << endl; 
            cout << "   > Ano de gravacao: " << this->anoGravacao << endl; 
        }

        ~Cancao() {
            cout << "- Destrutor " << this->nome << endl; 
        }        

};


int main() {

    Cancao *e1 = new Cancao("Amish Paradise", "Weird AI", 1996);
    e1->print();

    Cancao *e2 = new Cancao("Sete Mares", "Setima Legiao", 1997);
    e2->print();

    Cancao *e3 = new Cancao("Siga a Malta", "Galandum Galundaina", 2015);
    e3->print();


    delete e1; 
    delete e2; 
    delete e3; 


    vector<Cancao> cancoes;
    cancoes.push_back(Cancao("Amish Paradise", "Weird AI", 1996));
    cancoes.push_back(Cancao("Sete Mares", "Setima Legiao", 1997));
    cancoes.push_back(Cancao("Siga a Malta", "Galandum Galundaina", 2015));

    return 0;
}