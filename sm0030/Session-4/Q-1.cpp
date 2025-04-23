#include <iostream>

int main() {
  int a = 4;
  int *ptr_a = &a;
  std::cout << *ptr_a << std::endl;

  int b = 61;
  int *ptr_b = &b;
  std::cout << *ptr_b << std::endl;

  return 0;
}