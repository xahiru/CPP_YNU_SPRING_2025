#include <iostream>

int main() {
  // Declare variables to store length, width, area, and perimeter
  double length, width, area, perimeter;

  // Display a descriptive message
  std::cout << "Find the Area and Perimeter of a Rectangle :" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  // Prompt the user to input the length
  std::cout << "Input the length of the rectangle : ";
  std::cin >> length;

  // Prompt the user to input the width
  std::cout << "Input the width of the rectangle : ";
  std::cin >> width;

  // Calculate the area of the rectangle
  area = length * width;

  // Calculate the perimeter of the rectangle
  perimeter = 2 * (length + width);

  // Display the calculated area
  std::cout << "The area of the rectangle is : " << area << std::endl;

  // Display the calculated perimeter
  std::cout << "The perimeter of the rectangle is : " << perimeter << std::endl;

  return 0; // Indicate successful program execution
}