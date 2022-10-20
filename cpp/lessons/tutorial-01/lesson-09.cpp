#include <iostream>
#include <vector>

using namespace std;

struct Planets{
    string name;
    float gravity;
};

int main() {
    int cn = 1;
    int peso, index;

    vector<Planets> planets;
    planets.push_back({ "Mercurio", 0.38 });
    planets.push_back({ "Venos", 0.91 });
    planets.push_back({ "Marte", 0.38 });
    planets.push_back({ "Jupiter", 2.34 });
    planets.push_back({ "Saturno", 1.06 });
    planets.push_back({ "Urano", 0.92 });
    planets.push_back({ "Neptuno", 1.19 });

    cout << "Indique o seu peso no planeta Terra: ";
    cin >> peso;

    cout << "Indique qual o planeta para onde gostaria de viajar: ";
    cout << endl;

    for(int i=0; i<planets.size(); i++) {
        cout << "[" << cn++ << "] " << planets[i].name << endl;
    }      

    cin >> index;
    index = index - 1;
    
    cout << endl << "No planeta " << planets[index].name << " teria " << planets[index].gravity * peso << "Kg"<< endl;

    return 0;     
}
