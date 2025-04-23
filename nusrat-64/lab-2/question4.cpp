#include <iostream>
#include <cmath>

int main() {
    float radius, area, circumference;
    const float PI = 3.1416;

    std::cout << "Find the area and circumference of any circle :" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    std::cout << "Input the radius (1/2 of diameter) of a circle: ";
    std::cin >> radius;

    area = PI * pow(radius, 2);           
    circumference = 2 * PI * radius;      
    std::cout << "The area of the circle is: " << area << std::endl;
    std::cout << "The circumference of the circle is: " << circumference << std::endl;

    return 0;
}