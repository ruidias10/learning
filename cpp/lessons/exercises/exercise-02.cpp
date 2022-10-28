#include <iostream>

using namespace std;


string jogador(int size, string opcoes[], string jogador) {
    string j = "";

    while (j == "") {
        string tmp_operacao = "";
        cout << "Indique uma operacao para o " << jogador << ": " << endl;
        cout << " > Opcoes: ";

        for(int i = 0; i < size; i++) {
            string separador = (i + 1 != size) ? ", " :  ": ";
            cout << opcoes[i] << separador;
        } 

        cin >> tmp_operacao;
        for(int i = 0; i < size; i++) {
            if(tmp_operacao == opcoes[i]) {
                j = tmp_operacao;
            }
        }         
    }  

    return j;
}

int main() {

    string jogador1, jogador2 = "";

    string opcoes[] = {"Pedra", "Papel", "Tesoura"};
    int size = *(&opcoes + 1) - opcoes;

    jogador1 = jogador(size, opcoes, "jogador 1");
    jogador2 = jogador(size, opcoes, "jogador 2");



    if (jogador1 == jogador2) {
        cout << " > Resultador: Empate!";
    }
    // J1 vence
    else if (
       (jogador1 == "Pedra" && jogador1 == "Tesoura") ||
       (jogador1 == "Tesoura" && jogador1 == "Papel") ||
       (jogador1 == "Papel" && jogador1 == "Pedra")
    ) {
        cout << " > Resultador: Jogador 1 ganhou"; 
    }
    
    else {
        cout << " > Resultador: Jogador 2 ganhou";
    }



    /*
        if (jogador1 == "Pedra") {
            if (jogador2 == "Pedra") {
                cout << " > Resultador: Empate!";
            } else if (jogador2 == "Papel") {
                cout << " > Resultador: Jogador 2 ganhou";            
            } else if (jogador2 == "Tesoura") {
                cout << " > Resultador: Jogador 1 ganhou";            
            } else {
                cout << " > Resultador: Opcao invalida!";
            }       
        }

        else if (jogador1 == "Papel") {
            if (jogador2 == "Pedra") {
                cout << " > Resultador: Jogador 1 ganhou";   
            } else if (jogador2 == "Papel") {
                cout << " > Resultador: Empate!";       
            } else if (jogador2 == "Tesoura") {
                cout << " > Resultador: Jogador 2 ganhou";            
            } else {
                cout << " > Resultador: Opcao invalida!";
            }       
        }

        else if (jogador1 == "Tesoura") {
            if (jogador2 == "Pedra") {
                cout << " > Resultador: Jogador 2 ganhou";   
            } else if (jogador2 == "Papel") {
                cout << " > Resultador: Jogador 1 ganhou";    
            } else if (jogador2 == "Tesoura") {
                cout << " > Resultador: Empate!";            
            } else {
                cout << " > Resultador: Opcao invalida!";
            }       
        }  

        else {
            cout << " > Resultador: Opcao invalida!";
        }   
    */    


    cout << endl << "-------------------------------" << endl;

    return 0;
}