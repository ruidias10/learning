#include <iostream>

//using namespace std;
//cout << 4 + 2 << "\n";

int main() {
  std::cout << "Hell World!\n";

  std::cout << 4 + 2 << "\n";
  std::cout << 4 - 2 << "\n";
  std::cout << 4 * 2 << "\n";
  
  std::cout << 4 / 2 << "\n";
  std::cout << 5 / 2 << "\n";
  std::cout << 5 % 2 << "\n";
 
  int soma = 2 + 2;
  soma = soma + 42;
  std::cout << soma << "\n";


  // Tipos de dados
  int i = 1;
  std::cout << i << "\n";

  double d = 1.2;
  std::cout << d << "\n";
  
  float f = 1.222222212f;
  std::cout << f << "\n";

  std::string s = "String";
  std::cout << s << "\n";

  char c = 'C';
  std::cout << c << "\n";

  bool b = true;
  std::cout << b << "\n";

  auto tipoAutomatico = 12.1212121212121;
  std::cout << tipoAutomatico << "\n";

  return 0;
} 
