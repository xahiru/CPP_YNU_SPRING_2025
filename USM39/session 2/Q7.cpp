#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sphere_volume(double radius) {
    return (4.0/3.0) * M_PI * pow(radius, 3);
}

int main() {
    cout << "Calculate the volume of a sphere :\n";
    
    double radius;
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    
    cout << "The volume of a sphere is : " << fixed << setprecision(2) << sphere_volume(radius) << endl;
    
    return 0;
}