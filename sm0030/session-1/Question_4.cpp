#include <iostream>

int main() {
  int a = 10, b = 250;

  std::cout << "Variables initially: a = " << a << ", b = " << b << std::endl;

  int temp = a;
  a = b;
  b = temp;

  std::cout << "After execution: a = " << a << ", b = " << b << std::endl;
  return 0;
}