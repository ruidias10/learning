#include <iostream>
#include <vector>

using namespace std;

int main() {

    // matrizes

    //float gps[][] = { {3,2}, {4,5}, {5,6} };
    float gps[3][2] = { {3,2}, {4,5}, {5,6} };

    for (int i = 0; i < 3; i++) {
        cout << "POS: " << i << " ";
        cout << "LAT: " << gps[i][0] << ", LONG: " << gps[i][1] << endl;
    }

    cout << "\n"; 

    return 0;
}