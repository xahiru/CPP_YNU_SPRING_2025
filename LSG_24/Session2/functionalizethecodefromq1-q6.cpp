#include <iostream>
#include <cmath>
using namespace std;

double sphereVolume(double radius) {
    const double PI = 3.1416;
    return (4.0 / 3) * PI * pow(radius, 3);
}

int main() {
    double radius;
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    cout << "The volume of a sphere is : " << sphereVolume(radius) << endl;
    return 0;
}