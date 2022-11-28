#include <iostream>

using namespace std;

class Aluno {
    public:
        string nome;
        int cartaoCidadao;

        Aluno(string nome, int cartaoCidadao);

        void setNome(string nome);
        string getNome();

        void setCartaoCidadao(int cartaoCidadao);
        int getCartaoCidadao();    
};