#include <iostream>

using namespace std;

class Animal {
    public:
        string nome;

        virtual void respirar() {
            cout << "Sei respirar pelos pulmoes" << endl;
        }
};

class Roedor : public Animal {

};

class Golfinho : public Animal {
    
};

class Gafanhoto : public Animal {
    public:
        virtual void respirar() override {
            cout << "Sei respirar pela carapaca" << endl;
        }    
};


int main() {
    Animal animal;
    Roedor roedor;
    Golfinho golfinho;
    Gafanhoto gafanhoto;

    animal.respirar();
    cout << typeid(animal).name() << endl << endl;

    roedor.respirar();
    cout << typeid(roedor).name() << endl << endl;

    golfinho.respirar();
    cout << typeid(golfinho).name() << endl << endl;

    gafanhoto.respirar();
    cout << typeid(gafanhoto).name() << endl << endl;    

    // cast
    ((Animal)gafanhoto).respirar();
    cout << typeid((Animal)gafanhoto).name() << endl << endl;  
 
    return 0;
}