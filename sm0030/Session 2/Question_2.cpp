#include <iostream>

int main() {
    int side, volume;

    std::cout << "Calculate the volume of a cube :\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Input the side of a cube : ";
    std::cin >> side;

    volume = side * side * side;

    std::cout << "The volume of a cube is : " << volume << std::endl;

    return 0;
}