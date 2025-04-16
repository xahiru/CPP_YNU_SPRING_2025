#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float radius;
    cout << "Calculate the volume of a sphere :\n";
    cout << "---------------------------------------\n";
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    float volume = (4.0 / 3) * M_PI * pow(radius, 3);
    cout << "The volume of a sphere  is : "<< volume << endl;
    return 0;
}