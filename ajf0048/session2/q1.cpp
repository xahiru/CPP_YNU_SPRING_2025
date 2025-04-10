#include <iostream>
using namespace std;

double volumeOfSphere(double r, double PI = 3.14);

int main() {
    double r;
    cout << "Calculate the volume of a sphere :" << endl;
    
    cout << "Input the radius of a sphere : ";
    cin >> r;
    double volume = volumeOfSphere(r);
    cout << "The volume of a sphere is : " << volume << endl;
    return 0;
}

double volumeOfSphere(double r, double PI){
        return (4.0 / 3.0) * PI * (r *r *r);
}