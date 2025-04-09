#include <iostream>
#include <cmath> // For using the value of pi (M_PI)

int main() {
  // Declare variables to store radius, area, and circumference
  double radius, area, circumference;

  // Display a descriptive message
  std::cout << "@Safial" << std::endl;
  std::cout << "Find the area and circumference of any circle :" << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;

  // Prompt the user to input the radius
  std::cout << "Input the radius(1/2 of diameter) of a circle : ";
  std::cin >> radius;

  // Calculate the area of the circle
  area = M_PI * radius * radius;

  // Calculate the circumference of the circle
  circumference = 2 * M_PI * radius;

  // Display the calculated area
  std::cout << "The area of the circle is : " << area << std::endl;

  // Display the calculated circumference
  std::cout << "The circumference of the circle is : " << circumference << std::endl;

  return 0; // Indicate successful program execution
}