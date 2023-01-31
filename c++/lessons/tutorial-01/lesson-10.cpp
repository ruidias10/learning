#include <iostream>
#include <vector>

using namespace std;

struct Ingredientes{ 
    string name;
};

int main() {

    string i1, i2;

    vector<Ingredientes> ingrediente;
    ingrediente.push_back({ "Arroz" });
    ingrediente.push_back({ "Feijao" });
    ingrediente.push_back({ "Tofu" });
    ingrediente.push_back({ "Batata" });
    ingrediente.push_back({ "Porco" });
    ingrediente.push_back({ "Frango" });
    ingrediente.push_back({ "Carapau" });
   
    cout << "Ingredientes disponiveis" << endl;

    for(int i=0; i<ingrediente.size(); i++) {
        cout << ingrediente[i].name << endl;
    } 

    cout << "Indique qual o primeiro ingrdiente: ";
    cin >> i1;

    cout << "Indique qual o segundo ingrdiente: ";
    cin >> i2;

    cout << endl;


    return 0;     
}    