#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

//https://cplusplus.com/reference/vector/vector/pop_back/


using namespace std;

class Editora {
    public:
        string nome;
        string artista;
        int ano;
        vector<string> cancoes;

        Editora(string nome, string artista, int ano, vector<string> cancoes = {}) {
            this->nome = nome;
            this->artista = artista;
            this->ano = ano;
            this->cancoes = cancoes;
            
            cout << "+ Construtor " << this->nome << endl; 
        }


        string getNome() {
            return this->nome;
        }
        void setNome(string nome) {
            this->nome = nome;
        }


        string getArtista() {
            return this->artista;
        }
        void setArtista(string artista) {
            this->artista = artista;
        }    


        int getano() {
            return this->ano;
        }
        void setano(int ano) {
            this->ano = ano;
        }                


        void setCancoes(vector<string> novasCancoes){
            this->cancoes = novasCancoes;
        }
        vector<string> getCancoes(){
            return this->cancoes;
        }


        void adicionarCancao(string novaCancao){
            //adiciona no fim
            this->cancoes.push_back(novaCancao);

            //adiciona no inicio
            //this->cancoes.push_front(novaCancao);
        }      
        bool removeCancao(string cancao){
            int size = this->cancoes.size();

            if (!this->cancoes.empty()) {
                for (int i = 0; i < size; i++) {
                    if (cancoes[i] == cancao) {

                        //apagar o ultimo
                        //this->cancoes.pop_back();

                        //apagar o primeiro
                        //this->cancoes.pop_front();  
                                      
                        this->cancoes.erase(this->cancoes.begin() + i); 
                        return true;
                    }
                }
            }

            return false;
        }           


        void listarCancoes() {
            int size = this->cancoes.size();

            for (int i = 0; i < size; i++) {
               cout << "     > " << this->cancoes[i] << endl;  
            }
        }


        void print() {
            int size = this->cancoes.size();

            cout << "   > Nome: " << this->nome << endl; 
            cout << "   > Artista: " << this->artista << endl; 
            cout << "   > Ano de gravacao: " << this->ano << endl; 

            cout << "   > Lista de cancoes: " << endl;  
            for (int i = 0; i < size; i++) {
               cout << "     > " << this->cancoes[i] << endl;  
            }
        }

        ~Editora() {
            cout << "- Destrutor " << this->nome << endl;
        }        

};



void menuEditora(Editora editora) {
    int inputInt;
    string inputString;

    cout << endl << endl << "Menu da Editora " << editora.getNome() << endl;
    cout << "Escolha uma opcao: " << endl;
    cout << "\t[1] - Adicionar uma cancao" << endl;
    cout << "\t[2] - Remover uma cancao" << endl;
    cout << "\t[3] - Listar cancoes" << endl;
    cout << endl << "\t[0] - Sair do menu" << endl;

    cin >> inputInt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    switch (inputInt) {
        case 0:
            break;

        case 1:
            cout << "Escolha o nome da cancao a adicionar: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, inputString);
            editora.adicionarCancao(inputString);
            break;

        case 2:
            cout << "Escolha o nome da cancao a remover: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, inputString);
            editora.removeCancao(inputString);
            break;       

        case 3:
            cout << "Lista de cancoes da editora " << editora.getNome() << endl;
            editora.listarCancoes();
            cout << endl;
            break;                            
    }
}


int main() {

    vector<string> listaCancoes = { "Amish Paradise", "Sete Mares", "Siga a Malta" };



    // =======================================================================
    Editora *e1 = new Editora("Amish Paradise", "Weird AI", 1996);
    e1->adicionarCancao("Cancao 1");
    e1->adicionarCancao("Cancao 2");
    e1->adicionarCancao("Cancao 3");

    e1->removeCancao("Cancao 1");
    e1->print();

    Editora *e2 = new Editora("Sete Mares", "Setima Legiao", 1997);
    e2->adicionarCancao("Cancao 1");
    e2->adicionarCancao("Cancao 2");
    e2->adicionarCancao("Cancao 3");    

    e2->removeCancao("Cancao 2");
    e2->print();

    Editora *e3 = new Editora("Siga a Malta", "Galandum Galundaina", 2015, listaCancoes);
    e3->adicionarCancao("Cancao 1");
    e3->adicionarCancao("Cancao 2");
    e3->adicionarCancao("Cancao 3");       

    e3->removeCancao("Cancao 3");
    e3->print();

    delete e1; 
    delete e2; 
    delete e3;



    // =======================================================================
    vector<Editora> editoras = {};
    editoras.push_back(Editora("Amish Paradise", "Weird AI", 1996, listaCancoes));
    editoras.push_back(Editora("Sete Mares", "Setima Legiao", 1997, listaCancoes));
    editoras.push_back(Editora("Siga a Malta", "Galandum Galundaina", 2015, listaCancoes));



    // =======================================================================
    vector<Editora> editoras2 = {};
    Editora sony = Editora("Pretty Woman", "Roy Orbison", 1997);
    sony.adicionarCancao("M 1");
    sony.adicionarCancao("M 2");

    Editora xpto = Editora("2 Pretty Woman", "Roy Orbison", 1997);
    xpto.adicionarCancao("M 21");
    xpto.adicionarCancao("M 22");    

    editoras2.push_back(sony);
    editoras2.push_back(xpto);
    


    // =======================================================================
    int inputInt;
    string inputString;
    bool continuar = true;

    vector<Editora> listaEditoras = {};
    Editora UniversalMusic = Editora("Universal Music", "", 0);
    
    Editora *sony2 = new Editora("Sony", "", 1950);
    cout << "&sony2 " << &sony2 << " " << sony2->getNome() << endl;
    sony2 = &UniversalMusic;
    cout << "&sony2 " << &sony2 << " " << sony2->getNome() << endl;
    //delete sony2;  // apaga a UniversalMusic
    cout << "UniversalMusic "  << UniversalMusic.getNome() << endl;

    listaEditoras.push_back(UniversalMusic);

    while (continuar) {
        cout << endl << endl << "Menu das Editoras" << endl;
        cout << "Escolha uma opcao: " << endl;
        cout << "\t[1] - Adicionar uma editora" << endl;
        cout << "\t[2] - Remover uma editora" << endl;
        cout << "\t[3] - Ver uma editora" << endl;
        cout << "\t[4] - Listar as editoras" << endl;
        cout << endl << "\t[0] - Sair" << endl;

        cin >> inputInt;

        switch (inputInt) {
            case 0:
            {
                continuar = false;
                break; 
            } 

            case 1:
            {
                int anoNovaEditora;
                string nomeNovaEditora;
                vector<string> listaCancoesNovaEdotora = {};

                cout << "Nome da editora: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                getline(cin, nomeNovaEditora);   

                cout << "Ano da editora: " << endl;
                cin >> anoNovaEditora;    

                cout << "Adicione lista de cancoes separada por virgulas (,): " << endl;   
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                getline(cin, inputString);   
                
                stringstream streamMusicas(inputString);

                while (streamMusicas.good()) {
                    string token;
                    getline(streamMusicas, token, ',');
                    cout << token << endl;
                    listaCancoesNovaEdotora.push_back(token);
                }

                Editora x(nomeNovaEditora, "", anoNovaEditora, listaCancoesNovaEdotora);
                listaEditoras.push_back(x);
                
                break;
            }

            case 2:
            {
                cout << "Indique o nome da editora a remover: " << endl;   
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                getline(cin, inputString);                 

                int size = listaEditoras.size();

                if (!listaEditoras.empty()) {
                    for (int i = 0; i < size; i++) { 
                        Editora item = listaEditoras[i];

                        if (item.getNome() == inputString) {
                            listaEditoras.erase(listaEditoras.begin() + i); 
                            break;
                        }
                    }
                }                

                break; 
            } 

            case 3:
            {
                cout << "Indique o nome da editora que deseja ver: " << endl;   
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                getline(cin, inputString);                 

                bool existe = false;
                int size = listaEditoras.size();

                if (!listaEditoras.empty()) {
                    for (int i = 0; i < size; i++) { 
                        Editora item = listaEditoras[i];

                        if (item.getNome() == inputString) {
                            menuEditora(item);
                            existe = true;
                            break;
                        }
                    }
                } 

                if (!existe) {
                    cout << "A editora " << inputString << " nao existe." << endl;  
                } 

                break; 
            }  

            case 4:
            {
                cout << "Lista das editoras: " << endl;

                int size = listaEditoras.size();

                if (!listaEditoras.empty()) {
                    for (Editora item : listaEditoras) { 
                        cout << " > " << item.getNome() << endl;
                    }
                } 

                break; 
            }                  

        }







    }


    return 0;
}