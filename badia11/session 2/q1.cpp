#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float radius, volume;
    const float PI = 3.14159;

    cout << "Calculate the volume of a sphere:\n";
    cout << "---------------------------------\n";
    cout << "Input the radius of a sphere: ";
    cin >> radius;

    volume = (4.0 / 3.0) * PI * pow(radius, 3);

    cout << "The volume of a sphere is: " << volume << endl;
    return 0;
}

