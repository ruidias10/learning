#include <iostream>

using namespace std;


int main() {

    if ((2 == 3) ^ (2 == 2)) {
        cout << "^ OU \n";
    }



    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i : num) {
        cout << i << " ";
    }

    cout << "\n";



    int count = 1;

    while (++count < 10) {
        cout << count << "x" << count << "=" << count * count << "\n";
        // count++;
    }


    cout << "\n";

    return 0;
}