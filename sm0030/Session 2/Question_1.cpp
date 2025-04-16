#include <iostream>
#include <iomanip> 

int main() {
    double radius, volume;
    const double PI = 3.14159265358979323846; 

    std::cout << "Calculate the volume of a sphere :\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Input the radius of a sphere : ";
    std::cin >> radius;


    volume = (4.0 / 3.0) * PI * radius * radius * radius;

   
    std::cout << "The volume of a sphere is : " << std::fixed << std::setprecision(2) << volume << std::endl;

    return 0;
}