#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    cout << "Find the area and circumference of any circle :\n";
    cout << "Input the radius(1/2 of diameter) of a circle : ";
    double radius;
    cin >> radius;
    
    double area = M_PI * pow(radius, 2);
    double circumference = 2 * M_PI * radius;
    
    cout << "The area of the circle is : " << fixed << setprecision(4) << area << endl;
    cout << "The circumference of the circle is : " << fixed << setprecision(4) << circumference << endl;
    
    return 0;
}