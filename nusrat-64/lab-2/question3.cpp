#include <iostream>

int main() {
    int length, width, area, perimeter;

    std::cout << "Find the Area and Perimeter of a Rectangle :" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "Input the length of the rectangle: ";
    std::cin >> length;

    std::cout << "Input the width of the rectangle: ";
    std::cin >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    std::cout << "The area of the rectangle is: " << area << std::endl;
    std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;

    return 0;
}