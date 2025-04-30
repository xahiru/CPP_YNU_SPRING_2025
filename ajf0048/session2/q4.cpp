#include <iostream>
#include <cmath>
using namespace std;

void circleAreaAndCircumference(double r, double PI = 3.14) {
    double area = PI * (r * r);
    double circumference = 2 * PI * r;
    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;
}

int main() {
    double r;
    cout << "Find the area and circumference of any circle :" << endl;
    cout << "Input the radius(1/2 of diameter) of a circle : ";
    cin >> r;
    circleAreaAndCircumference(r);
    return 0;
}