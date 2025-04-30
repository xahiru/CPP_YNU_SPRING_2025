
#include <iostream>
using namespace std;

int main() {
    double side, volume;

    // Ask the user for input
    cout << "Calculate the volume of a cube :\n";
    cout << "---------------------------------------\n";
    cout << "Input the side of a cube : ";
    cin >> side;

    // Formula for the volume of a cube: V = side³
    volume = side * side * side;

    // Output the result
    cout << "The volume of a cube is : " << volume << endl;

    return 0;
}
