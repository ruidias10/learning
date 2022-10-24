#include <string>
#include <iostream>

using namespace std;


// tudo dentro do struct é publico
struct Human {
    // valores default
    Human() {
        name = "Human";
        age = 0;
        height = 0.87f;
        weight = 0.12f;
    }

    Human(string n, int a = 10) {
        name = n;
        age = a;
        height = 0.87f;
        weight = 0.12f;
    }    

    void Show() {
        cout << "name: " << this->name << endl;
        cout << "age: " << this->age << endl;
        cout << "height: " << this->height << endl;
        cout << "weight: " << this->weight << endl;
    }

    string name;

    int age;
    float height;
    float weight;
};


// tudo dentro do class é privado
class Humano {
    public: 
        string name;

    private:
        int age;
        float height;
        float weight;  
};



void print(string message, int value) {
    cout << message << " " << value << endl;
}

void printReferencia(string message, int& value) {
    int tmp = value;
    value = value + 1;
    cout << message << " " << tmp << " > " << value << endl;
}


int main(int argc, char** argv) {
    cout << "argc: " << argc << endl;
    cout << "argv: " << argv << endl;

    // semelhante ao int sem sinal 
    size_t sizeT = 0; 
    
    // o ultimo elemento, o 11 é sempre o "\0"
    char charArray[11] = "0123456789";

    // string #include <string>
    string myString = "Std";



    int myInt[10];

    for (int i=0; i<10; i++) {
        int c = i * 10;
        myInt[i] = c;
        printReferencia("Alterar o valor:", c);
        print("Imprime o valor:", c);
    }



    cout << "-----------------------------------------------" << endl;


    Human me;
    me.name = "Rui";
    me.age = 100;
    me.height = 20.5f;
    me.weight = 10.7f;

    me.Show();
    cout << endl;


    Human you;
    you.Show();  
    cout << endl; 


    Human he("Rui Dias");
    cout << "he.name: " << he.name << endl;
    cout << "he.age: " << he.age << endl;
    cout << "he.height: " << he.height << endl;
    cout << "he.weight: " << he.weight << endl;   
    cout << endl;    

    

    system("ls");

    return 0;
}