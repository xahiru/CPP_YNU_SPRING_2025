#include <iostream>
#define PI 3.1416

int main() {
    double r;
    std::cout << "Enter radius: ";
    std::cin >> r;
    std::cout << "Volume: " << (4.0 / 3.0) * PI * r * r * r << std::endl;
    return 0;
}
