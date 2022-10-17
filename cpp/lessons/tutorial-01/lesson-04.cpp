#include <iostream>

int main(){

  int num;
  std::cout << "Indique um valor inteiro: ";
  std::cin >> num;

  if (num % 2 == 0) {
    std::cout << "O numero " << num << " e par" << std::endl;
  } else {
    std::cout << "O numero " << num << " e impar" << std::endl;
  }

  return 0;
}
