#include <iostream>
#include <iomanip> // For setw() formatting (optional)

int main() {
    double side;

    std::cout << "Calculate the volume of a cube \n";
    std::cout << "Input the side of a cube : ";
    std::cin >> side;

    double volume = side * side * side;

    std::cout << "The volume of a cube is : " << volume << std::endl;

    return 0;
}