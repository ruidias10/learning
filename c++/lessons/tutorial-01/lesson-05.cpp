#include <iostream>

int main() {

    int num;

    std::cout << "Indique um numero: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << "O numero " << num <<" e positivo!" << std::endl;
    } else if (num < 0) {
        std::cout << "O numero " << num <<" e negativo!" << std::endl;
    } else {
        std::cout << "O " << num <<" e zero!" << std::endl;
    }

    return 0;
}