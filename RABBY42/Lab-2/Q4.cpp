#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double PI = 3.14159265358979323846;
    double radius, area, circumference;
    
    cout << "Find the area and circumference of any circle :" << endl;
    cout << "----------------------------------------------------" << endl;
    
    // Get radius input from user
    cout << "Input the radius(1/2 of diameter) of a circle : ";
    cin >> radius;
    
    // Calculate area (A = πr²) and circumference (C = 2πr)
    area = PI * pow(radius, 2);
    circumference = 2 * PI * radius;
    
    // Set precision to 6 decimal places for the output
    cout << fixed << setprecision(4);
    

    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;
    
    return 0;
}