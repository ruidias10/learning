#include <iostream>

using namespace std;

class Pessoa {
    public:
        string nome;
        string dataNascimento;
        string NIF;
        string nacionalidade; // ENUM


        //construtor
        Pessoa() {
            cout << "> Construtor default " << endl; 
        }   

        /* 
        Pessoa(string nome, string dataNascimento, string NIF) {
            this->nome = nome;
            this->dataNascimento = dataNascimento;
            this->NIF = NIF;
        } 
        */
        
        Pessoa(string nome, string dataNascimento, string NIF): nome (nome), dataNascimento(dataNascimento), NIF(NIF) {
            cout << "> Construtor parametros " << endl; 
        }        


        //destrutor
        ~Pessoa() {
            cout << "> Destrutor " << this->nome << endl; 
        }
};


int main() {

    Pessoa pessoa;
    pessoa.nome = "Rui";
    pessoa.dataNascimento = "2000-01-01";
    pessoa.NIF = "000 000 000";

   cout << "Nome: "<< pessoa.nome << endl;
   cout << "Data Nascimento: "<< pessoa.dataNascimento << endl;
   cout << "NIF: "<< pessoa.NIF << endl;     
   cout << endl;       



   Pessoa pessoa1("Ze", "2000-01-01", "000 000 000");
   
   cout << "Nome: "<< pessoa1.nome << endl;
   cout << "Data Nascimento: "<< pessoa1.dataNascimento << endl;
   cout << "NIF: "<< pessoa1.NIF << endl;   
   cout << endl;       



   Pessoa *pessoa2 = new Pessoa("Manuel", "2000-01-01", "000 000 000");
   
   cout << "Momoria: "<< pessoa2 << endl;
   cout << "Nome: "<< pessoa2->nome << endl;
   cout << "Nome: "<< (*pessoa2).nome << endl;
   cout << "Data Nascimento: "<< pessoa2->dataNascimento << endl;
   cout << "NIF: "<< pessoa2->NIF << endl;
   cout << endl;     

   delete pessoa2;  

    return 0;
}