#include <iostream>
#include <vector>

using namespace std;

int main() {

    int size;
    string input;
    bool is_palindrome;
    vector<char> inverse;

    do {

        inverse.clear();
        is_palindrome = true;

        cout << "Insira um numero, ou 0 para terminar: ";
        cin >> input;

        size = input.length();

        for (int i = (size-1); i >= 0; i--) {
            inverse.push_back(input[i]); //string(1, input[i])
        }

        for (int i = 0; i < size; i++) {
            if (input[i] != inverse[i]) {
                is_palindrome = false;
                break;
            }
        } 
      
        if (is_palindrome) {
            cout << " > O numero " << input << " e palindroma" << endl;
        } else {
            cout << " > OPS! O numero " << input << " nao e palindroma" << endl;
        }

        cout << endl;

    } while(input != "0");

    return 0;
}