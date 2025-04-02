#include <iostream>

int main() {
  char character;

  std::cout << "Enter a character: ";
  std::cin >> character;

  int asciiValue = static_cast<int>(character);

  std::cout << "ASCII Value of '" << character << "' = " << asciiValue << std::endl;

  return 0;
}