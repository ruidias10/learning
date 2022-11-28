#include <iostream>
#include <cstdlib>
#include <vector>
#include <string> 
#include <random>

using namespace std;


// Cria um inteiro aleatorios
int helperGeraInt() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 60000);
    
    srand(dis(gen));    

    return rand();
}

// Cria uma string capitalize de comprimento variavel
string helperGeraString(int length) {
    int ch_MAX = 26;
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };  

    string name = "";

    for (int i = 0; i< length; i++) {
        name = name + alpha[helperGeraInt() % ch_MAX];
    }

    name[0] = toupper(name[0]); 

    if (name == "") {
        return "Default";
    }

    return name;
}



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

        Turma(string ano, int identificador, vector<Aluno*> alunos = {}) {
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
                this->identificador = helperGeraInt() % 1000;
                return;
            }
            
            this->identificador = identificador;
        }      
};



class Escola {
    public:
        int numero;
        string nome;
        string localidade;
        vector<Turma> turmas;

        Escola(int numero, string nome, string localidade, vector<Turma*> turmas = {}) {

        }        

        void setNumero(int numero) {
            this->numero = numero;
        }

        int getNumero() {
            return this->numero;
        }      


        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return this->nome;
        }   


        void setLocalidade(string localidade) {
            this->localidade = localidade;
        }

        string getLocalidade() {
            return this->localidade;
        }                    
};







vector<Aluno*> builderAlunos(int length) {
    vector<Aluno*> listaAlunos = {};

    for (int i = 0; i < length; i++) {
        int cartaoCidadao = helperGeraInt();

        string nome = helperGeraString(helperGeraInt()%10);
        string sobreNome = helperGeraString(helperGeraInt()%20);
        string nomeCompleto = nome + " " + sobreNome;

        Aluno* a = new Aluno(nomeCompleto, cartaoCidadao); 
        listaAlunos.push_back(a);
    }

    return listaAlunos;
}


Turma* builderTurma(vector<Aluno*> alunos) {
    vector<Aluno*> listaAlunos = builderAlunos(30);

    int identificador = helperGeraInt()%100;
    string ano = to_string(helperGeraInt()%12) + " " +  helperGeraString(1);
    
    Turma* t = new Turma(ano, identificador, alunos);  
    
    return t;
}

Escola builderEscola() {
    
}




int main() {

    cout << "Imprime qualquer coisa" << endl;

    vector<Aluno*> listaAlunos = builderAlunos(30);
    Turma* t = builderTurma(listaAlunos);


    int size = listaAlunos.size();

    for (int i = 0; i < size; i++) {
        Aluno* a = listaAlunos[i];
        cout << "ALUNO: " << a->getNome() << " " << a->getCartaoCidadao() << endl;
    }

    
    
    cout << "TURMA: " << t->getAno() << " " << t->getIdentificador() << endl;


    cout << endl;

    return 0;
}
