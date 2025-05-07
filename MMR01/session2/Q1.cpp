#include <iostream>
#include <cmath> // For pow() function
using namespace std;

int main() {
    const float PI = 3.14; // Defining the value of PI
    float radius, volume;
    
    cout << "Calculate the volume of a sphere :\n";
    
    // Input the radius from user
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    
    // Calculate volume using formula V = (4/3) * π * r³
    volume = (4.0 / 3.0) * PI * pow(radius, 3);
    
    cout << "The volume of a sphere is : " << volume << endl;
    
    return 0;
}