#include <iostream>
#include <vector>

using namespace std;

// $ man ascii

string touppercase(string input) {
    char ch;
    int dec;
    string output;

    for (int i = 0; i < input.length(); i++) {
        dec = (int)input[i];

        if (dec > 96 && dec < 123) {
            char ch = (char)(int)input[i] - 32;
            output += ch;
        } else {
            output += input[i];
        }
    }

    return output;
}


string tolowercase(string input) {
    char ch;
    int dec;
    string output;

    for (int i = 0; i < input.length(); i++) {
        dec = (int)input[i];

        if (dec > 64 && dec < 91) {
            char ch = (char)(int)input[i] + 32;
            output += ch;
        } else {
            output += input[i];
        }
    }

    return output;
}


int main() {

    cout << touppercase("Vou BeBer CAfe!") << endl;

    cout << tolowercase("gOSTO De GeLAdOS!") << endl;

    return 0;
}