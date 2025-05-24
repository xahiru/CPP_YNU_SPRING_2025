#include <iostream>
#include <iomanip> 
#include <cmath>   

using namespace std;

int main() {
    double radius, volume;

    cout << "Calculate the volume of a sphere :" << endl;
    cout << "Input the radius of a sphere : ";
    cin >> radius;

    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);

    cout << "The volume of a sphere is : " << fixed << setprecision(2) << volume << endl;

    return 0;
}