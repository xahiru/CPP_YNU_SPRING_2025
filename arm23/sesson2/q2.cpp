#include <iostream>
using namespace std;

int main() {
    float side;
    cout << "Calculate the volume of a cube :\n";
    cout << "----------------------------------------\n";
    cout << "Input the side of a cube : ";
    cin >> side;
    float volume = side * side * side;
    cout << "The volume of a cube is : " << volume << endl;
    return 0;
}