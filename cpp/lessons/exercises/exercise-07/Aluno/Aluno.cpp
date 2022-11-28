#include <iostream>
#include "Aluno.h"

using namespace std;

Aluno::Aluno(string nome, int cartaoCidadao) {
    this->setNome(nome);
    this->setCartaoCidadao(cartaoCidadao);
}        


void Aluno::setNome(string nome) {
    this->nome = nome;
}

string Aluno::getNome() {
    return this->nome;
}


void Aluno::setCartaoCidadao(int cartaoCidadao) {
    this->cartaoCidadao = cartaoCidadao;
}

int Aluno::getCartaoCidadao() {
    return this->cartaoCidadao;
}        
