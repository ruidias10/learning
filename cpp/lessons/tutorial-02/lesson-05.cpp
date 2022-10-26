#include <iostream>

using namespace std;

int main() {

    struct estudante {
        int matricula;
        string nome;
        float media;
    };

    struct estudante stud1, *ptr_stud1;
    ptr_stud1 = &stud1;

    ptr_stud1->matricula = 123;
    ptr_stud1->nome = "Rui Dias";
    ptr_stud1->media = 10.5;
    
    stud1.matricula = 456;
    stud1.nome = "Rui";
    stud1.media = 11.5;

    cout << stud1.media << endl;
    cout << ptr_stud1->media << endl;
    
    return 0;
}