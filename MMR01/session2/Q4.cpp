#include <iostream>
#include <iomanip>  // For setprecision()
#include <cmath>    // For M_PI constant

int main() {
    double radius;
    const double PI = 3.14159265358979323846;  // can also use M_PI from <cmath>

    std::cout << "Find the area and circumference of any circle \n";
    
    // Get radius input
    std::cout << "Input the radius(1/2 of diameter) of a circle : ";
    std::cin >> radius;

    // Calculate area (πr²) and circumference (2πr)
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;

    // Set precision to 4 decimal places for output
    std::cout << std::fixed << std::setprecision(4);
    
    // Display results
    std::cout << "The area of the circle is : " << area << "\n";
    std::cout << "The circumference of the circle is : " << circumference << "\n";

    return 0;
}