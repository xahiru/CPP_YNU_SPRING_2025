#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Calculate the volume of a cube :\n";
    cout << "Input the side of a cube : ";
    double side;
    cin >> side;
    
    double volume = pow(side, 3);
    cout << "The volume of a cube is : " << volume << endl;
    
    return 0;
}