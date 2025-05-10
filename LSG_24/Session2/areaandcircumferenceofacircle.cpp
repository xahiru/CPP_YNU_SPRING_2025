#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double radius, area, circumference;
    const double PI = 3.1416;

    cout << "Find the area and circumference of any circle :" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Input the radius(1/2 of diameter) of a circle : ";
    cin >> radius;

    area = PI * pow(radius, 2);
    circumference = 2 * PI * radius;

    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;

    return 0;
}