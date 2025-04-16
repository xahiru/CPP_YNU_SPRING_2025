#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Calculate the volume of a sphere :\n";
    cout << "Input the radius of a sphere : ";
    double radius;
    cin >> radius;
    double volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "The volume of a sphere is : " << volume << endl;
    return 0;
}