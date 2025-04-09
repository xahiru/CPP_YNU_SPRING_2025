#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double side, volume;
    
    cout << "Calculate the volume of a cube :" << endl;
    cout << "---------------------------------------" << endl;
    
    cout << "Input the side of a cube : ";
    cin >> side;
    
    // volume of cube: V = side³
    volume = side * side * side;
    
    cout << "The volume of a cube is : " << volume << endl;
    
    return 0;
}