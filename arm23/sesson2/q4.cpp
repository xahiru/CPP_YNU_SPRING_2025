#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float radius;
    cout << "Find the area and circumference of any circle :\n";
    cout << "---------------------------------------------------\n";
    cout << "Input the radius (1\2 of diameter) of a circle : ";
    cin >> radius;
    cout << "The area of the circle is : " << M_PI * radius << endl;
    cout << "The circumference of the circle is : " << 2 * M_PI * radius << endl;
    return 0;
}