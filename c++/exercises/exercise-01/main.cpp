#include <iostream>

using namespace std;

int main() {

    int num1, num2;
    string operacao = "";

    string opcoes[] = {"Soma", "Subtracao", "Multiplicacao", "Divisao"};
    int size = *(&opcoes + 1) - opcoes;


    cout << "Indique o 1 numero: ";
    cin >> num1;

    cout << "Indique o 2 numero: ";
    cin >> num2;    

    while (operacao == "") {
        string tmp_operacao = "";
        cout << "Indique uma operacao: " << endl;
        cout << " > Opcoes: ";

        for(int i = 0; i < size; i++) {
            string separador = (i + 1 != size) ? ", " :  ": ";
            cout << opcoes[i] << separador;
        } 

        cin >> tmp_operacao;
        for(int i = 0; i < size; i++) {
            if(tmp_operacao == opcoes[i]) {
                operacao = tmp_operacao;
            }
        }         
    }    

    cout << " > Resultado: ";

    if (operacao == "Soma") {
        cout << num1 << " + " << num2 << " = " << num1 + num2;
    } else if (operacao == "Subtracao") {
        cout << num1 << " - " << num2 << " = " << num1 - num2;
    } else if (operacao == "Multiplicacao") {
        cout << num1 << " * " << num2 << " = " << num1 * num2;
    } else if (operacao == "Divisao") {
        cout << num1 << " / " << num2 << " = " << num1 / num2;
    }    

    cout << endl << "-------------------------------" << endl;

    return 0;
}