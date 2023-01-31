#include <iostream>

using namespace std;


string dar_agua_as_plantas(int dias, bool suculentas) {

    if (dias > 3 && !suculentas) {
        return "E tempo de regar as plantas.";
    }

    else if (dias < 12 && suculentas) {
        return "Nao regue as plantas.";
    } 

    else if (dias > 12 && suculentas) {
        return "Por favor regue as plantas!";
    }        

    return "Nao regue as plantas.";
}

int main() {

    cout << dar_agua_as_plantas(10, false) << endl;
    cout << dar_agua_as_plantas(15, false) << endl;
    cout << dar_agua_as_plantas(3, true) << endl;

    return 0;
}