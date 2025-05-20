#include <iostream>
using namespace std;

int main() {
    double side, volume;

    cout << "Calculate the volume of a cube :\n";
    cout << "---------------------------------------\n";
    cout << "Input the side of a cube : ";

    cin >> side;

    volume = side * side * side;

    cout << "The volume of a cube is : " << volume << endl;

    return 0;
}