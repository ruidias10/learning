#include <iostream>

int main(){

  int num;
  std::cout << "Indique um valor inteiro: ";
  std::cin >> num;

  if (num % 2 == 0) {
    std::cout << "O numero " << num << " e par\n";
  } else {
    std::cout << "O numero " << num << " e impar\n";
  }

  return 0;
}
