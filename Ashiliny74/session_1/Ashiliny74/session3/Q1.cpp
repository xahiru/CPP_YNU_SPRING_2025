#include <iostream>
#include <iomanip> // For setprecision and fixed

using namespace std;

int main() {
    double radius, volume;
    
    cout << "Calculate the volume of a sphere :" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Input the radius of a sphere : ";
    cin >> radius;
    
    // Calculate volume using formula (4/3)πr³ with π approximated as 3.14
    volume = (4.0 / 3.0) * 3.14 * radius * radius * radius;
    
    // Set output to display exactly 2 decimal places
    cout << fixed << setprecision(2);
    cout << "The volume of a sphere is : " << volume;
    
    return 0;
}