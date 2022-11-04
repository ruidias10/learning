#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string nome = "CAFE";

    cout << nome << endl;

    cout << nome.find("E") << endl;

    cout << nome.length() << endl;

    transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
    cout << nome << endl;

    transform(nome.begin(), nome.end(), nome.begin(), ::toupper);
    cout << nome << endl;         

    reverse(nome.begin(), nome.end());
    cout << nome << endl;

    return 0;
}