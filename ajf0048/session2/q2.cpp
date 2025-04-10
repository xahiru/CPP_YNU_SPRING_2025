#include <iostream>
using namespace std;

double volumeOfCube(double r);

int main() {
    double r;
    cout << "Calculate the volume of a cube :" << endl;
    cout << "Input the side of a cube : ";
    cin >> r;
    double volume = volumeOfCube(r);
    cout << "The volume of a cube is : " << volume << endl;
    return 0;
}

double volumeOfCube(double r) {
    return r*r*r;
}