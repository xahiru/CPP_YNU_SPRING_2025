#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double radius, area, circumference;

    cout << "Find the circumference of any circle :\n";
    cout << "----------------------------------------------------\n";
    cout << "Input the radius (1/2 of diameter) of a circle : ";

    cin >> radius;

    area = M_PI * radius * radius;

    circumference = 2 * M_PI * radius;

    cout << "The  are of a circlr is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;

    return 0;
}