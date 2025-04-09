#include <iostream>
#include <cmath>

int main() {
    int side, volume;

    std::cout << "Calculate the volume of a cube :" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Input the side of a cube: ";
    std::cin >> side;

    volume = pow(side, 3);

    std::cout << "The volume of a cube is: " << volume << std::endl;

    return 0;
}