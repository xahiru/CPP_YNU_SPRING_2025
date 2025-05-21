#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double radius;

    // Input radius
    cout << "Find the area and circumference of any circle :" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Input the radius (1/2 of diameter) of a circle : ";
    cin >> radius;

    // Calculate area and circumference
    double area = M_PI * radius * radius; // M_PI is a constant for the value of pi
    double circumference = 2 * M_PI * radius;

    // Output the results
    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;

    return 0;
}
