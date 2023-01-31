#include <iostream>

int main() {
  std::cout << "Printing stuff to the console" << std::endl;
  std::cerr << "Error: Something went wrong" << std::endl;
  std::clog << "Log: This is a log message" << std::endl;


  std::cout << "Type your full name: ";
  std::string full_name;
  std::getline(std::cin, full_name);
  std::cout << "Hello " << full_name << std::endl;


  int number1 = 15; // Decimal
  int number2 = 017; // Octal
  int number3 = 0x0F; // Hexadecimal
  int number4 = 0b00001111; // Binary

  std::cout << "number1: " << number1 << std::endl;
  std::cout << "number2: " << number2 << std::endl;
  std::cout << "number3: " << number3 << std::endl;
  std::cout << "number4: " << number4 << std::endl;
  
  return 0;
}