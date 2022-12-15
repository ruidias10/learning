#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {
    private:
        int idade;
        string nome;
    
    public:
      Cliente(string nome, int idade) 
            : nome (nome), idade (idade) { 
      }

      string getNome() {
        return this->nome;
      }

      void setNome(string nome) {
        this->nome = nome;
      }

      int getIdade() {
        return this->idade;
      }

      void setIdade(int idade) {
        this->idade = idade;
      }
};


class Conta {
    private:
        int id;
        double saldo;
        double descobertoMaximo;
        Cliente* cliente;

    public:
        const char* name;

        Conta(int novoId, double novoSaldo, double novoDescoberto, Cliente* cliente)
            : id (novoId), saldo (novoSaldo), descobertoMaximo (novoDescoberto), cliente (cliente)  {
                this->name = "Conta";
        }

        virtual string getContaNome() {
            return this->name;
        }

        Cliente* getCliete() {
            return this->cliente;
        }

        int getId() {
            return this->id;
        }

        double getSaldo() {
            return this->saldo;
        }

        double getDescoberto() {
            return this->descobertoMaximo;
        }

        void setId(int novoId) {
            this->id = novoId;
        }

        void setSaldo(double novoSaldo) {
            this->saldo = novoSaldo;
        }

        virtual void setDescoberto(double novoDescoberto) {
            this->descobertoMaximo = novoDescoberto;
        }

        virtual void actualizacaoMensal() {
            cout << " >> Actualização da conta" << endl;
        }

        bool depositar(double valor) {
            if (valor < 0) {
                cout << " >> O valor que pretende depositar deve ser maior do que 0.0€" << endl;
                return false;
            } 

            this->setSaldo(this->getSaldo() + valor);
            return true;
        }

        virtual bool levantar(double valor) {
            if (valor < 0) {
                cout << " >> O valor que pretende levantar deve ser maior do que 0.0€" << endl;
                return false;

            } else if(this->getSaldo() < valor) {
                cout << " >> O seu saldo nao permite efetuar o levantamento de " << valor << "€" << endl;
                return false;
            }

            this->setSaldo(this->getSaldo() - valor);
            return true;
        }  

        virtual void mensalidade() {
            this->setSaldo(this->getSaldo() - 1.00);
        } 

        bool transferir(double valor, Conta* conta) {
            if (this->getSaldo() < valor) {

                cout << " >> Saldo insuficiente para efetuar transferencia" << endl;
            }

            return conta->depositar(this->levantar(valor));
        }
};


class ContaOrdenado : public Conta {
    private:
        double juroCredito;

    public:
        const char* name;

        ContaOrdenado(int id, double saldo, double descoberto, double novoJuro, Cliente* cliente)
            : Conta(id, saldo, descoberto, cliente), juroCredito(novoJuro) {
                this->name = "Conta Ordenado";
            }

        virtual string getContaNome() override {
            return this->name;
        }

        double getJuro() {
            return this->juroCredito;
        }

        void setJuro(double novoJuro) {
            this->juroCredito = novoJuro;
        }

        virtual void actualizacaoMensal() override {
            if (this->getSaldo() < 0) {
                double novoSaldo = 0;
                novoSaldo = this->getSaldo() * (1 + this->getJuro() / 12);

                this->setSaldo(novoSaldo);
            }
        }

        virtual bool levantar(double valor) override {
            if (valor < 0) {
                cout << " >> O valor que pretende levantar deve ser maior do que 0.0€" << endl;
                return false;

            } else if((this->getSaldo() + this->getDescoberto()) < valor) {
                cout << " >> O seu saldo nao permite efetuar o levantamento de " << valor << "€" << endl;
                return false;
            }

            this->setSaldo(this->getSaldo() - valor);
            return true;
        }        
};


class ContaPoupanca : public Conta {
    private:
        double juro;

    public:
        const char* name;

        ContaPoupanca(int id, double saldo, double descoberto, double novoJuro, Cliente* cliente)
            : Conta(id, saldo, descoberto, cliente), juro(novoJuro) {
                this->name = "Conta Poupanca";
            }

        virtual string getContaNome() override {
            return this->name;
        }

        double getJuro() {
            return this->juro;
        }

        void setJuro(double novoJuro) {
            this->juro = novoJuro;
        }

        virtual void actualizacaoMensal() override {
            double novoSaldo = 0;
            novoSaldo = this->getSaldo() * (1 + this->getJuro() / 12);

            this->setSaldo(novoSaldo);
        }
};

class ContaServicosMinimos : public Conta {
    public:
        const char* name;

        ContaServicosMinimos(int id, double saldo, double descoberto, Cliente* cliente)
            : Conta(id, saldo, 0, cliente) {
                this->name = "Conta Servicos Minimos";
            }

        virtual string getContaNome() override {
            return this->name;
        }

        virtual void setDescoberto(double novoDescoberto) override {
            Conta::setDescoberto(0);
        }

        virtual void mensalidade() override {}         
};

class ContaEstudante : public Conta {
    public:
        const char* name;

        ContaEstudante(int id, double saldo, double descoberto, Cliente* cliente)
            : Conta(id, saldo, 0, cliente) {
                this->name = "Conta Estudante";

                if (cliente->getIdade() < 6 || cliente->getIdade() > 26) {
                    cout << " >> As contas estudante apenas sao validas para clientes com idade superir a 6 anos e inferior a 27!" << endl;
                }
            }

        virtual string getContaNome() override {
            return this->name;
        }

        virtual void setDescoberto(double novoDescoberto) override {
            Conta::setDescoberto(0);
        }

        virtual void mensalidade() override {}     
};

class ContaAforroJunior : public Conta {
    public:
        const char* name;

        ContaAforroJunior(int id, double saldo, double descoberto, Cliente* cliente)
            : Conta(id, saldo, 0, cliente) {
                this->name = "Conta Aforro Junior";

                if (cliente->getIdade() > 7) {
                    cout << " >> Contas Aforro Junior apenas sao validas para clientes com idade inferiores a 7 anos!" << endl;
                }
            }

        virtual string getContaNome() override {
            return this->name;
        }

        virtual void setDescoberto(double novoDescoberto) override {
            Conta::setDescoberto(0);
        }

        virtual void mensalidade() override {}           
};

class ContaInvestidor : public Conta {
    private:
        double capitalAplicadoProdutosRisco;
    
    public:
        const char* name;

        ContaInvestidor(int id, double saldo, double descoberto, double capitalAplicadoProdutosRisco, Cliente* cliente)
            : Conta(id, saldo, descoberto, cliente), capitalAplicadoProdutosRisco(capitalAplicadoProdutosRisco) {
                this->name = "Conta Investidor";
            }     

        virtual string getContaNome() override {
            return this->name;
        }

        double getCapitalAplicadoProdutosRisco() {
            return this->capitalAplicadoProdutosRisco;
        }

        void adicionarCapitalAplicadoProdutosRisco(double capitalAplicadoProdutosRisco) {
            this->capitalAplicadoProdutosRisco += capitalAplicadoProdutosRisco;
        }  

        void retirarCapitalAplicadoProdutosRisco(double capitalAplicadoProdutosRisco) {
            this->capitalAplicadoProdutosRisco -= capitalAplicadoProdutosRisco;
        }                      
};

int main() {

    vector<Conta*> contas = {};


    Cliente* clienteOrdenado = new Cliente("José Manuel", 30);
    Conta* contaOrdenado = new ContaOrdenado(1, 100, 100, 0.12, clienteOrdenado);

    Cliente* clientePoupanca = new Cliente("Maria Alice", 60);
    Conta* contaPoupanca = new ContaPoupanca(2, 50, 100, 0.12, clientePoupanca);

    Cliente* clienteServicosMinimos = new Cliente("José Manuel", 70);
    Conta* contaServicosMinimos = new ContaServicosMinimos(3, 500, 0, clienteServicosMinimos);

    Cliente* clienteEstudante = new Cliente("João Silva", 18);
    Conta* contaEstudante = new ContaEstudante(4, 410, 0, clienteEstudante);

    Cliente* clienteAforroJunior = new Cliente("Ivo Martins", 5);
    Conta* contaAforroJunior = new ContaAforroJunior(5, 910, 0, clienteAforroJunior);

    Cliente* clienteInvestidor = new Cliente("João Paulo", 40);
    Conta* contaInvestidor = new ContaInvestidor(5, 500, 10, 500, clienteInvestidor);


    contas.push_back(contaOrdenado);
    contas.push_back(contaPoupanca);
    contas.push_back(contaServicosMinimos);
    contas.push_back(contaEstudante);
    contas.push_back(contaAforroJunior);
    contas.push_back(contaInvestidor);




    for (Conta* item : contas) {

        Cliente* cliente = item->getCliete();

        cout << item->getContaNome() << " Id: " << item->getId() << " Titular: " << cliente->getNome() << " Saldo: " << item->getSaldo() << endl; 
        
        item->depositar(500);
        cout << " > depositar 500 > novo saldo: " << item->getSaldo() << endl; 
        
        item->levantar(100);
        cout << " > levantar 100 > novo saldo: " << item->getSaldo() << endl; 

        item->levantar(1000);
        cout << " > tenta levantar 1000 > novo saldo: " << item->getSaldo() << endl;      

        item->depositar(-20);
        cout << " > tenta depositar -20 > novo saldo: " << item->getSaldo() << endl; 

        item->mensalidade();
        cout << " > paga mensalidade > novo saldo: " << item->getSaldo() << endl;         

        item->actualizacaoMensal();  
        cout << " > depois da actualizacao mensal > novo saldo: " << item->getSaldo() << endl;     
        
        cout << " > valor descoberto: " << item->getDescoberto() << endl;   
        
        item->setDescoberto(300);
        cout << " > novo valor descoberto: " << item->getDescoberto() << endl;   

        cout << endl << endl;  
    }

    cout << " > antes da transferencia saldo: " << contaInvestidor->getSaldo() << endl;
    contaInvestidor->transferir(100, contaAforroJunior);
    cout << " > transferiu 100 > novo saldo: " << contaInvestidor->getSaldo() << endl;
    cout << " > recebeu 100 por transferencia > novo saldo: " << contaAforroJunior->getSaldo() << endl;

    cout << endl << endl; 

    delete contaOrdenado;
    delete contaPoupanca;
    delete contaServicosMinimos;
    delete contaEstudante;
    delete contaAforroJunior;
    delete contaInvestidor;

    delete clienteOrdenado;
    delete clientePoupanca;
    delete clienteServicosMinimos;
    delete clienteEstudante;
    delete clienteAforroJunior;
    delete clienteInvestidor;

    return 0;
}