#include <iostream>
#include <vector>

using namespace std;

int main() {

    int input;
    vector<int> pairNumbers;
    vector<int> oddNumbers;

    do {
        cout << "Insira um numero: ";
        cin >> input;

        if (input != 0) {
            if (input % 2 == 0) {
                pairNumbers.push_back(input);
            } else {
                oddNumbers.push_back(input);
            }
        }

    } while(input != 0);


    cout << "\n";  
    cout << "Numeros impares: " << oddNumbers.size() << endl;
    for (int i = 0; i < oddNumbers.size(); i++) {
        cout << oddNumbers[i] << ", ";
    }


    cout << "\n";  
    cout << "Numeros pares: " << pairNumbers.size() << endl;
    for (int i = 0; i < pairNumbers.size(); i++) {
        cout << pairNumbers[i] << ", ";
    }


    cout << "\n";  

    return 0;
}