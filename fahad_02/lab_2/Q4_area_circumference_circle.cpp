#include <iostream>
#include <cmath>    

using namespace std;

int main() {
    double rad, area, circumference;

    cout << "Input the radius (1/2 of diameter) of a circle : ";
    cin >> rad;

    area = M_PI * pow(rad, 2);
    circumference = 2 * M_PI * rad;

    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << fixed;
    cout.precision(0);
    cout << circumference << endl;

    return 0;
}
