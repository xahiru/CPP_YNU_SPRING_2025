#include <iostream>
#include <cmath>

int main() {
    float radius, volume;
    const float PI = 3.1416;

    std::cout << "Calculate the volume of a sphere :" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Input the radius of a sphere: ";
    std::cin >> radius;

    volume = (4.0 / 3.0) * PI * pow(radius, 3);

    std::cout << "The volume of a sphere is: " << volume << std::endl;

    return 0;
}