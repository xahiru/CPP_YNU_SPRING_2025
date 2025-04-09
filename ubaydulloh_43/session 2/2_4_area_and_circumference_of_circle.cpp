#include <iostream>
#include <iomanip> 
#include <cmath>   

using namespace std;

int main() {
    double radius, area, circumference;

    cout << "Find the area and circumference of any circle :" << endl;
    cout << "Input the radius (1/2 of diameter) of a circle : ";
    cin >> radius;

    area = M_PI * pow(radius, 2);
    circumference = 2 * M_PI * radius;

    cout << fixed << setprecision(4); 
    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;

    return 0;
}