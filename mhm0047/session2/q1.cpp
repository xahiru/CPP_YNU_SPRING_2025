#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double vol, red;
    cout << "Input the radius of a sphere : ";
    cin >> red;
    vol = (4.0 / 3.0) * M_PI * pow(red, 3);
    cout << "The volume of a sphere is : " << vol << endl;
    return 0;
}