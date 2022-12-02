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

class Helper {
    public:
        // Cria um inteiro aleatorios
        static int randomNumbers(int length = 60000) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, length);

            return dis(gen);
        } 

        // Cria uma string capitalize de comprimento variavel
        static string randomWords(int length) {
            int ch_MAX = 26;
            char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };  

            string name = "";

            for (int i = 0; i< length; i++) {
                name = name + alpha[Helper::randomNumbers(ch_MAX)];
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
};



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
                this->identificador = Helper::randomNumbers(1000);
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


class Builder {

};




vector<Aluno*> builderAlunos(int length) {
    vector<Aluno*> listaAlunos = {};

    for (int i = 0; i < length; i++) {
        int cartaoCidadao = Helper::randomNumbers();

        string nome = Helper::randomWords(Helper::randomNumbers(10));
        string sobreNome = Helper::randomWords(Helper::randomNumbers(20));
        string nomeCompleto = nome + " " + sobreNome;

        Aluno* a = new Aluno(nomeCompleto, cartaoCidadao); 
        listaAlunos.push_back(a);
    }

    return listaAlunos;
}

vector<Turma*> builderTurmas(vector<Aluno*> listaAlunos, int length) {
    vector<Turma*> listaTurmas = {};

    for (int i = 0; i < length; i++) {
        int identificador = Helper::randomNumbers(100);
        string ano = to_string(Helper::randomNumbers(12)) + Helper::randomWords(1);
        
        Turma* turma = new Turma(ano, identificador, listaAlunos); 
        listaTurmas.push_back(turma);
    }
    
    return listaTurmas;
}

vector<Escola*> builderEscola(int length) {
    vector<Escola*> listaEscolas = {};

    for (int i = 0; i < length; i++) {
        int numero = Helper::randomNumbers(12);
        string nome = Helper::randomWords(Helper::randomNumbers(10));
        string localidade = Helper::randomWords(Helper::randomNumbers(20));

        vector<Aluno*> listaAlunos = builderAlunos(Helper::randomNumbers(15));
        vector<Turma*> listaTurmas = builderTurmas(listaAlunos, Helper::randomNumbers(5));
        
        Escola* escola = new Escola(numero, nome, localidade, listaTurmas);
        listaEscolas.push_back(escola);
    }

    return listaEscolas;
}

void showAllDataInMemory(vector<Escola*> listaEscolas = {}) {
    for (Escola* escola : listaEscolas) {
        cout << "Escola"
             << " - Nome: " << escola->getNome()
             << " - Numero: " << escola->getNumero() 
             << " - Localidade: " << escola->getLocalidade()
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






void listSchools(vector<Escola*> listaEscolas = {}) {
    for (Escola* escola : listaEscolas) {
        cout << "Escola"
             << " - Nome: " << escola->getNome()
             << " - Numero: " << escola->getNumero() 
             << " - Localidade: " << escola->getLocalidade()
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
                << " - Localidade: " << escola->getLocalidade()
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

            break;
        }
    }
}

void showClasses(int numero, vector<Escola*> listaEscolas = {}) {
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {
            cout << "Escola"
                << " - Nome: " << escola->getNome()
                << " - Numero: " << escola->getNumero() 
                << " - Localidade: " << escola->getLocalidade()
                << endl;

            for (Turma* turma : escola->getTurmas()) {
                cout << "   Turma"
                    << " - Ano: " << turma->getAno()
                    << " - Identificador: " << turma->getIdentificador() 
                    << endl;

                cout << endl;
            }

            break;
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
    getline(cin, localidade);

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
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, localidade);  

    Escola* escola = new Escola(num, nome, localidade);
    listaEscolas.push_back(escola);
}


void addClasse(int numero, vector<Escola*> &listaEscolas) {
    int identificador;
    string ano;

    cout << "Indique o identificador da turma: ";
    cin >> identificador;  

    cout << "Indique o ano da turma: ";  
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, ano);

    Turma* turma = new Turma(ano, identificador); 

    int key = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {
            escola->turmas.push_back(turma);
            break;
        }

        key++;
    }
}


void deleteClasse(int numero, int identificador, vector<Escola*> &listaEscolas) {
    int escolaKey = 0;
    int turmaKey = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {
                    turma->alunos.clear();
                    listaEscolas[escolaKey]->turmas.erase(listaEscolas[escolaKey]->turmas.begin() + turmaKey);
                   break; 
                }

                turmaKey++;
            } 

            break;           
        }

        escolaKey++;
    }
}



void updateClasse(int numero, int identificador, vector<Escola*> &listaEscolas) {
    int novoIdentificador;
    string ano;

    cout << "Indique o novo identificador da turma: ";
    cin >> novoIdentificador;

    cout << "Indique o novo ano da turma: " ;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, ano); 

    int escolaKey = 0;
    int turmaKey = 0;

    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {
                    //listaEscolas[escolaKey]->turmas.erase(listaEscolas[escolaKey]->turmas.begin() + turmaKey);
                    listaEscolas[escolaKey]->turmas[turmaKey]->setAno(ano);
                    listaEscolas[escolaKey]->turmas[turmaKey]->setIdentificador(novoIdentificador);
                   break; 
                }

                turmaKey++;
            } 

            break;           
        }

        escolaKey++;
    }  
}

void showStudents(int numero, int identificador, vector<Escola*> &listaEscolas) {
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {
                    for (Aluno* aluno : turma->getAlunos()) {
                        cout << "     Aluno"
                            << " - Nome: " << aluno->getNome()
                            << " - CC: " << aluno->getCartaoCidadao() 
                            << endl;                
                    }
                   break; 
                }
            } 

            break;           
        } 
    } 
}


void addStudent(int numero, int identificador, vector<Escola*> &listaEscolas) {
    string nome;
    int cartaoCidadao;

    cout << "Indique o cartao de cidacao do aluno: ";
    cin >> cartaoCidadao;  

    cout << "Indique o nome do aluno: ";  
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, nome);

    Aluno* aluno = new Aluno(nome, cartaoCidadao);

    int escolaKey = 0;
    int turmaKey = 0;

    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {
                    listaEscolas[escolaKey]->turmas[turmaKey]->alunos.push_back(aluno);
                   break; 
                }

                turmaKey++;
            } 

            break;           
        }

        escolaKey++;
    }    
}

void deleteStudent(int numero, int identificador, int cartaoCidadao, vector<Escola*> &listaEscolas) {
    int escolaKey = 0;
    int turmaKey = 0;
    int alunoKey = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) {

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {

                    for (Aluno* aluno : turma->getAlunos()) {
                        if (aluno->getCartaoCidadao() == cartaoCidadao) {
                            listaEscolas[escolaKey]->turmas[turmaKey]->alunos.erase(listaEscolas[escolaKey]->turmas[turmaKey]->alunos.begin() + alunoKey);
                            break;
                        }
                        alunoKey++;
                    }

                    break; 
                }

                turmaKey++;
            } 

            break;           
        }

        escolaKey++;
    }
}

void updateStudent(int numero, int identificador, int cartaoCidadao, vector<Escola*> &listaEscolas) {
    string nome;
    int novoCartaoCidadao;

    cout << "Indique o cartao de cidacao do aluno: ";
    cin >> novoCartaoCidadao;  

    cout << "Indique o nome do aluno: ";  
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, nome);


    int escolaKey = 0;
    int turmaKey = 0;
    int alunoKey = 0;
    for (Escola* escola : listaEscolas) {
        if (escola->getNumero() == numero) { 

            for (Turma* turma : escola->getTurmas()) {
                if (turma->getIdentificador()  == identificador) {

                    for (Aluno* aluno : turma->getAlunos()) {
                        if (aluno->getCartaoCidadao() == cartaoCidadao) {
                            listaEscolas[escolaKey]->turmas[turmaKey]->alunos[alunoKey]->setNome(nome);
                            listaEscolas[escolaKey]->turmas[turmaKey]->alunos[alunoKey]->setCartaoCidadao(novoCartaoCidadao);
                            break;
                        }
                        alunoKey++;
                    }

                    break; 
                }

                turmaKey++;
            } 

            break;           
        }

        escolaKey++;
    }

}



int mainOptionMenu() {

    int inputInt;
    bool isValid = false;

    do {
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << "    MENU DAS ESCOLAS (Escolha uma opcao)     " << endl;
        cout << "---------------------------------------------" << endl;

        cout << "\t[20] - Gerar dados automaticamente (random)" << endl;
        cout << "\t[30] - Gerir Escolas" << endl;
        cout << "\t[40] - Gerir Turmas" << endl;
        cout << "\t[50] - Gerir Alunos" << endl;

        cout << endl;
        cout << "\t[0] - Sair" << endl;
        
        cin >> inputInt;  
        isValid = (inputInt == 20 || inputInt == 30 || inputInt == 40 || inputInt == 50 || inputInt == 0);

        if (!isValid) {
            cout << "Infelizmente a opcao escolhida e invalida!" << endl;            
        }

    } while(!isValid);

    return inputInt;
}





int main() {

    // =======================================================================
    int inputInt;
    string inputString;
    bool continuar = true;
    vector<Escola*> listaEscolas = {};

    while (continuar) {

        inputInt = mainOptionMenu();
        

        switch (inputInt) {
            case 0: { // sair
                continuar = false;
                return 0;
                break; 
            } 

            case 20: {
                cout << "---------------------------------------------" << endl;
                cout << "    GERAR DADOS AUTOMATICAMENTE     " << endl;
                cout << "---------------------------------------------" << endl;               
                cout << "\t[1] - Criar dados automaticamente (random)" << endl;
                cout << "\t[2] - Listar todos os dados em memoria" << endl;
                break; 
            }             

            case 30: { // escolas
                cout << endl;
                cout << "---------------------------------------------" << endl;
                cout << "    ESCOLAS     " << endl;
                cout << "---------------------------------------------" << endl;            
                cout << "\t[3 ok] - Listar as escolas" << endl;
                cout << "\t[4 ok] - Adicionar uma escola" << endl;
                cout << "\t[5 ok] - Ver uma escola" << endl;
                cout << "\t[6 ok] - Eliminar uma escola" << endl;
                cout << "\t[7 ok] - Editar a escola" << endl;
                break; 
            } 

            case 40: { // turmas 
                cout << "---------------------------------------------" << endl;
                cout << "    TURMAS     " << endl;
                cout << "---------------------------------------------" << endl;                         
                cout << "\t[8 ok] - Listar as turmas de uma escola" << endl; 
                cout << "\t[9 ok] - Criar uma nova turma" << endl; 
                cout << "\t[10 ok] - Eliminar uma turma" << endl; 
                cout << "\t[11 ok] - Editar uma turma" << endl;
                break; 
            } 

            case 50: { // alunos
                cout << "---------------------------------------------" << endl;
                cout << "    ALUNOS     " << endl;
                cout << "---------------------------------------------" << endl;                        
                cout << "\t[12] - Listar os alunos de uma turma" << endl;
                cout << "\t[13] - Criar um novo aluno" << endl;
                cout << "\t[14] - Eliminar um aluno" << endl;
                cout << "\t[15] - Editar um aluno" << endl;
                break; 
            } 



        }


        cout << endl;


        cin >> inputInt;
        

        switch (inputInt) {

            case 1:
            {
                //Criar dados automaticamente (random)
                listaEscolas = builderEscola(2);
                break; 
            }  

            case 2:
            {
                //Listar todos os dados em memoria
                showAllDataInMemory(listaEscolas);
                break; 
            } 

            case 3:
            {
                //Listar as escolas
                listSchools(listaEscolas);
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

            case 8:
            {
                //Listar as turmas de uma escola
                int numeroEscola;
                cout << "Indique o numero da escola que ver as turmas: ";
                cin >> numeroEscola;
                showClasses(numeroEscola, listaEscolas);
                break;
            } 

            case 9:
            {
                //Criar uma nova turma 
                int numeroEscola;
                cout << "Indique o numero da escola para adicionar uma turma: ";
                cin >> numeroEscola;
                addClasse(numeroEscola, listaEscolas);
                break;
            } 

            case 10: 
            {
                //Eliminar uma turma
                int numeroEscola;
                int identificador;

                cout << "Indique o numero da escola para remover uma turma: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma: ";
                cin >> identificador;  

                deleteClasse(numeroEscola, identificador, listaEscolas);
                break;                
            }

            case 11: 
            {
                //Editar uma turma
                int numeroEscola;
                int identificador;

                cout << "Indique o numero da escola para editar uma turma: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma: ";
                cin >> identificador;  

                updateClasse(numeroEscola, identificador, listaEscolas);
                break;                
            }    

            case 12: 
            {
                //Listar os alunos de uma turma
                int numeroEscola;
                int identificador;

                cout << "Indique o numero da escola para listar os alunos de uma turma: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma para ver os alunos: ";
                cin >> identificador;  

                showStudents(numeroEscola, identificador, listaEscolas);
                break;                                   
            }

            case 13:
            {
                //Criar um novo aluno
                int numeroEscola;
                int identificador;

                cout << "Indique o numero da escola para listar os alunos de uma turma: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma para ver os alunos: ";
                cin >> identificador;  

                addStudent(numeroEscola, identificador, listaEscolas);
                break;                       
            }

            case 14:
            {
                //Eliminar um aluno
                int numeroEscola;
                int identificador;
                int cartaoCidadao;

                cout << "Indique o numero da escola onde quer apagar um aluno: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma onde quer apagar um aluno: ";
                cin >> identificador;  

                cout << "Indique cartao de cidadao do aluno que quer apagar: ";
                cin >> cartaoCidadao;                  

                deleteStudent(numeroEscola, identificador, cartaoCidadao, listaEscolas);
                break;                   
            }

            case 15: 
            {
                //Editar um aluno
                int numeroEscola;
                int identificador;
                int cartaoCidadao;

                cout << "Indique o numero da escola onde quer editar o aluno: ";
                cin >> numeroEscola;

                cout << "Indique o identificador da turma onde quer editar o aluno: ";
                cin >> identificador;  

                cout << "Indique cartao de cidadao do aluno que quer editar: ";
                cin >> cartaoCidadao;                  

                updateStudent(numeroEscola, identificador, cartaoCidadao, listaEscolas);
                break;                    
            }


                      

                                    

                                                             
        }
    }

    




    cout << endl;

    return 0;
}
