#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double radius, volume;
    const double PI = 3.1416;

    cout << "Calculate the volume of a sphere :" << endl;
    cout << "---------------------------------" << endl;
    cout << "Input the radius of a sphere : ";
    cin >> radius;

    volume = (4.0 / 3) * PI * pow(radius, 3);
    cout << "The volume of a sphere is : " << volume << endl;

    return 0;
}