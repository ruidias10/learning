#include <iostream>
#include <cstdlib>
#include <vector>
#include <string> 
#include <random>
#include <limits>
#include <sstream>

// #include "meucodigo.hpp"
// #pragma once // para nao haver includes repetidos


using namespace std;


// Cria um inteiro aleatorios
int helperGeraInt(int length = 60000) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, length);

    return dis(gen);
}

// Cria uma string capitalize de comprimento variavel
string helperGeraString(int length) {
    int ch_MAX = 26;
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };  

    string name = "";

    for (int i = 0; i< length; i++) {
        name = name + alpha[helperGeraInt(ch_MAX)];
    }

    if (name == "") {
        return "Default";
    }

    if (name[0] == ' ') {
        name[0] = 'a';
    }

    name[0] = toupper(name[0]);     

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
        vector<Aluno*> alunos;

        Turma(string ano, int identificador, vector<Aluno*> alunos = {}) {
            this->setAno(ano);
            this->setIdentificador(identificador);
            this->setAlunos(alunos);
        }

        void setAlunos(vector<Aluno*> alunos) {
            this->alunos = alunos;
        }

        vector<Aluno*> getAlunos() {
            return this->alunos;
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
                this->identificador = helperGeraInt(1000);
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
        vector<Turma*> turmas;

        Escola(int numero, string nome, string localidade, vector<Turma*> turmas = {}) {
            this->setNumero(numero);
            this->setNome(nome);
            this->setLocalidade(localidade);
            this->setTurmas(turmas);
        }     

        void setTurmas(vector<Turma*> turmas) {
            this->turmas = turmas;
        }

        vector<Turma*> getTurmas() {
            return this->turmas;
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

        string nome = helperGeraString(helperGeraInt(10));
        string sobreNome = helperGeraString(helperGeraInt(20));
        string nomeCompleto = nome + " " + sobreNome;

        Aluno* a = new Aluno(nomeCompleto, cartaoCidadao); 
        listaAlunos.push_back(a);
    }

    return listaAlunos;
}

vector<Turma*> builderTurmas(vector<Aluno*> listaAlunos, int length) {
    vector<Turma*> listaTurmas = {};

    for (int i = 0; i < length; i++) {
        int identificador = helperGeraInt(100);
        string ano = to_string(helperGeraInt(12)) + helperGeraString(1);
        
        Turma* turma = new Turma(ano, identificador, listaAlunos); 
        listaTurmas.push_back(turma);
    }
    
    return listaTurmas;
}

vector<Escola*> builderEscola(int length) {
    vector<Escola*> listaEscolas = {};

    for (int i = 0; i < length; i++) {
        int numero = helperGeraInt(12);
        string nome = helperGeraString(helperGeraInt(10));
        string localidade = helperGeraString(helperGeraInt(20));

        vector<Aluno*> listaAlunos = builderAlunos(helperGeraInt(15));
        vector<Turma*> listaTurmas = builderTurmas(listaAlunos, helperGeraInt(5));
        
        Escola* escola = new Escola(numero, nome, localidade, listaTurmas);
        listaEscolas.push_back(escola);
    }

    return listaEscolas;
}

void showDataInMemory(vector<Escola*> listaEscolas = {}) {
    for (Escola* escola : listaEscolas) {
        cout << "Escola"
             << " - Nome: " << escola->getNome()
             << " - Numero: " << escola->getNumero() 
             << " - Localidade: " << escola->getNome()
             << endl;

        for (Turma* turma : escola->getTurmas()) {
            cout << "   Turma"
                << " - Ano: " << turma->getAno()
                << " - Identificador: " << turma->getIdentificador() 
                << endl;

            for (Aluno* aluno : turma->getAlunos()) {
                cout << "     Aluno"
                    << " - Nome: " << aluno->getNome()
                    << " - CC: " << aluno->getCartaoCidadao() 
                    << endl;                
            }

            cout << endl;
        }

        cout << endl;
    }
}


void listAllSchools(vector<Escola*> listaEscolas = {}) {
    for (Escola* escola : listaEscolas) {
        cout << "Escola"
             << " - Nome: " << escola->getNome()
             << " - Numero: " << escola->getNumero() 
             << " - Localidade: " << escola->getNome()
             << endl;

        cout << endl;
    }
}

void showSchool(int numero, vector<Escola*> listaEscolas = {}) {

    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {
            cout << "Escola"
                << " - Nome: " << escola->getNome()
                << " - Numero: " << escola->getNumero() 
                << " - Localidade: " << escola->getNome()
                << endl;

            for (Turma* turma : escola->getTurmas()) {
                cout << "   Turma"
                    << " - Ano: " << turma->getAno()
                    << " - Identificador: " << turma->getIdentificador() 
                    << endl;

                for (Aluno* aluno : turma->getAlunos()) {
                    cout << "     Aluno"
                        << " - Nome: " << aluno->getNome()
                        << " - CC: " << aluno->getCartaoCidadao() 
                        << endl;                
                }

                cout << endl;
            }
        }
    }
}

void deleteSchool(int numero, vector<Escola*> &listaEscolas) {
    int key = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {
            listaEscolas.erase(listaEscolas.begin() + key); 
            break;
        }

        key++;
    }
}

void updateSchool(int numero, vector<Escola*> &listaEscolas) {
    int num;
    string nome;
    string localidade;

    cout << "Indique o novo numero da escola: ";
    cin >> num;

    cout << "Indique o novo nome da escola: " ;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, nome); 

    cout << "Indique a nova localidade da escola: " ; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   
    getline(cin, localidade);

    cout << "\t111111 num " << num << endl;
    cout << "\t111111 nome " << nome << endl;
    cout << "\t111111 localidade " << localidade << endl;

    int key = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {
            listaEscolas[key]->setNumero(num);
            listaEscolas[key]->setNome(nome);
            listaEscolas[key]->setLocalidade(localidade);
            break;
        }

        key++;
    }
}

void addSchool(vector<Escola*> &listaEscolas) {
    int num;
    string nome;
    string localidade;

    cout << "Indique o numero da escola: ";
    cin >> num;

    cout << "Indique o nome da escola: " ;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, nome);  

    cout << "Indique a localidade da escola: " ;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, localidade);  

    Escola* escola = new Escola(num, nome, localidade);
    listaEscolas.push_back(escola);
}







int main() {

    // =======================================================================
    int inputInt;
    string inputString;
    bool continuar = true;
    vector<Escola*> listaEscolas = {};

    while (continuar) {
        cout << endl;
        cout << "MENU DAS ESCOLAS (Escolha uma opcao:)" << endl;
            cout << "\t[1 ok] - Criar dados automaticamente (random)" << endl;
            cout << "\t[2 ok] - Listar todos os dados em memoria" << endl;
            cout << endl;
            cout << "\t[3 ok] - Listar as escolas" << endl;
            cout << "\t[4 ok] - Adicionar uma escola" << endl;
            cout << "\t[5 ok] - Ver uma escola" << endl;
            cout << "\t[6 ok] - Eliminar uma escola" << endl;
cout << "\t[7] - Editar os atributos basicos da escola" << endl;        
        cout << endl;
        cout << "\t[0] - Sair" << endl;

        cout << endl;
        cout << endl;    
        //cout << "\t[-] - Adicionar uma escola" << endl;
        //cout << "\t[-] - Eliminar uma escola" << endl;
        //cout << "\t[-] - Editar os atributos básicos da escola" << endl;
        cout << "\t[-] - Listar as turmas de uma escola" << endl;
        cout << "\t[-] - Criar uma nova turma" << endl;
        cout << "\t[-] - Eliminar uma turma" << endl;
        cout << "\t[-] - Editar uma turma" << endl;
        cout << "\t[-] - Listar os alunos de uma turma" << endl;
        cout << "\t[-] - Criar um novo aluno" << endl;
        cout << "\t[-] - Eliminar um aluno" << endl;
        cout << "\t[-] - Editar um aluno" << endl;

        cin >> inputInt;

        switch (inputInt) {
            case 0:
            {
                //Sair
                continuar = false;
                break; 
            } 

            case 1:
            {
                //Criar dados automaticamente (random)
                listaEscolas = builderEscola(2);
                break; 
            }  

            case 2:
            {
                //Listar todos os dados em memoria
                showDataInMemory(listaEscolas);
                break; 
            } 

            case 3:
            {
                //Listar as escolas
                listAllSchools(listaEscolas);
                break; 
            }              

            case 4:
            {
                //Criar uma escola
                addSchool(listaEscolas);
                break; 
            }  

            case 5:
            {
                //Ver uma escola
                int numeroEscola;
                cout << "Indique o numero da escola que quer ver: ";
                cin >> numeroEscola;
                showSchool(numeroEscola, listaEscolas);
                break;
            } 

            case 6:
            {
                //Eliminar uma escola
                int numeroEscola;
                cout << "Indique o numero da escola que quer eliminar: ";
                cin >> numeroEscola;
                deleteSchool(numeroEscola, listaEscolas);
                break;
            }   

            case 7:
            {
                //Editar os atributos basicos da escola
                int numeroEscola;
                cout << "Indique o numero da escola que quer editar: ";
                cin >> numeroEscola;
                updateSchool(numeroEscola, listaEscolas);
                break;
            }                        

                                                             
        }
    }

    




    cout << endl;

    return 0;
}
