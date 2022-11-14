#include <iostream>
#include <vector>

//https://cplusplus.com/reference/vector/vector/pop_back/


using namespace std;

class Editora {
    public:
        string nome;
        string artista;
        int anoGravacao;
        vector<string> cancoes;

        Editora(string nome, string artista, int anoGravacao, vector<string> cancoes = {}) {
            this->nome = nome;
            this->artista = artista;
            this->anoGravacao = anoGravacao;
            this->cancoes = cancoes;
            
            cout << "+ Construtor " << this->nome << endl; 
        }


        string setNome() {
            return this->nome;
        }
        void getNome(string nome) {
            this->nome = nome;
        }


        string setArtista() {
            return this->artista;
        }
        void getArtista(string artista) {
            this->artista = artista;
        }    


        int setAnoGravacao() {
            return this->anoGravacao;
        }
        void getAnoGravacao(int anoGravacao) {
            this->anoGravacao = anoGravacao;
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


        void print() {
            int size = this->cancoes.size();

            cout << "   > Nome: " << this->nome << endl; 
            cout << "   > Artista: " << this->artista << endl; 
            cout << "   > Ano de gravacao: " << this->anoGravacao << endl; 

            cout << "   > Lista de cancoes: " << endl;  
            for (int i = 0; i < size; i++) {
               cout << "     > " << this->cancoes[i] << endl;  
            }
        }

        ~Editora() {
            cout << "- Destrutor " << this->nome << endl;
        }        

};


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
    

    return 0;
}