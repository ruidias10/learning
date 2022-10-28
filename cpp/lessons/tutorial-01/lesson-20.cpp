#include <iostream>
#include <vector>

//using namespace std;

int main() {

    // vetores
    
    int input;
    int quantidade;
    std::vector<int> numeros;
    //std::vector<int> numeros = {1, 3, 5, 7, 9};
    //numeros.size()

    std::cout << "Insira quantos numeros vai digitar: ";
    std::cin >> quantidade;

    // numeros[i] = input; // para array
    for (int i = 0; i < quantidade; i++) {
        std::cout << "Insira o numero: ";
        std::cin >> input;
        numeros.push_back(input); // para vetores - acrescenta no fim
    }


    int tamanhoArray = sizeof(numeros) / sizeof(int);
    int numeroItemsVector = numeros.size();

    std::cout << "\n\n";
    std::cout << "tamanhoArray: " << tamanhoArray << "\n";      
    std::cout << "numeroItemsVector: " << numeroItemsVector << "\n";
    std::cout << "\n\n";      


    //int tamanho = sizeof(numeros) / sizeof(int) // para arrays
    //int tamanho = numeros.size(); // para vetor 
    for (int i = 0; i < numeros.size(); i++) {                
        std::cout << numeros[i] << ", ";
    }

    std::cout << "\n";  

    return 0;
}