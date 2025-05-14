#include <iostream>
#include <cmath>  // For M_PI constant and power function

using namespace std;

int main() {
    double radius, volume;

    // Ask the user for input
    cout << "Calculate the volume of a sphere :\n";
    cout << "---------------------------------------\n";
    cout << "Input the radius of a sphere : ";
    cin >> radius;

    // Formula for the volume of a sphere: V = (4/3) * π * r³
    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);

    // Output the result
    cout << "The volume of a sphere is : " << volume << endl;

    return 0;
}
