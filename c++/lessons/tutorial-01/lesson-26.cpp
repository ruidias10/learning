#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool palindroma(string palavra) {
    string inverse = palavra;
    reverse(inverse.begin(), inverse.end());
    
    return palavra == inverse;
}


bool superir(string palavra, int quantidade) {
    return palavra.length() > quantidade;
}


bool contem(string palavra, char letra) {
    int size = palavra.length();

    for (int i = 0; i < size; i++) {
        if (palavra[i] == letra) {
            return true;
        }
    }

    return false;
}


int main() {

    cout << "palindroma: " << palindroma("abccba") << endl;
    cout << "palindroma: " << palindroma("abcdef") << endl;

    cout << "superir: " << superir("abcdef", 5) << endl;    
    cout << "superir: " << superir("abcdef", 7) << endl;    

    cout << "contem: " << contem("abcdef", 'b') << endl;    
    cout << "contem: " << contem("abcdef", 's') << endl;    
 
    return 0;
}    