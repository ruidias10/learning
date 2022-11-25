#include <iostream>
#include <vector>

using namespace std;


class Aluno {
    public:
        string nome;
        int cartaoCidadao;

        Aluno(string nome, int cartaoCidadao) {
            this->setNome(nome);
            this->setCartaoCidadao(cartaoCidadao);
        }        


        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return this->nome;
        }


        void setCartaoCidadao(int cartaoCidadao) {
            this->cartaoCidadao = cartaoCidadao;
        }

        int getCartaoCidadao() {
            return this->cartaoCidadao;
        }        
};


class Turma {
    private:
        int identificador;

    public:
        string ano;
        vector<Aluno> alunos;

        Turma(string ano, int identificador) {
            this->setAno(ano);
            this->setIdentificador(identificador);
        }


        void setAno(string ano) {
            this->ano = ano;
        }

        string getAno() {
            return this->ano;
        }  


        int getIdentificador() {
            return this->identificador;
        }

        void setIdentificador(int identificador) {
            if (identificador < 0) {
                cout << "> O identificador da turma tem de ser um numero inteiro positivo" << endl;  
                this->identificador = 0;
                return;
            }
            
            this->identificador = identificador;
        }      
};



class Escola {
    public:
        int numero;
        string nome;
        string Localidade;
        vector<Turma> turmas;
};








int main() {


    cout << "Imprime qualquer coisa" << endl;

    cout << endl;

    return 0;
}
