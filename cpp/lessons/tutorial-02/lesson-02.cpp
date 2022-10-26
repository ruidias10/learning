#include <iostream>
#include <cstddef>

using namespace std;

int main() {
    /*
        int* p2;
        p2 = NULL;
        cout << p2 << " " << &p2 << " " << *p2 << endl;
    */

    int var1 = 10;
    int* p1 = &var1;
    int* p3 = new int;
    *p3 = 35;

    cout << var1 << " " << &var1 << endl;
    cout << p1 << " " << &p1 << " " << *p1 << endl;
    cout << p3 << " " << &p3 << " " << *p3 << endl;

    delete p3;

    return 0;
}