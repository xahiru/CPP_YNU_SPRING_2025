#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double PI = 3.14; // Defining π as a constant
    double radius, volume;
    
    cout << "Calculate the volume of a sphere :" << endl;
    cout << "---------------------------------------" << endl;
    
    // Get radius input from user
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    
    // Calculate volume of sphere: V = (4/3) * π * r³
    volume = (4.0 / 3.0) * PI * pow(radius, 3);
    
    // Set precision to 2 decimal places for the output
    cout << fixed << setprecision(2);
    
    // Display the result
    cout << "The volume of a sphere is : " << volume << endl;
    
    return 0;
}