#include <iostream>
#define PI 3.14159265359
using namespace std;

int main() {
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area: " << PI * r * r << "\nCircumference: " << 2 * PI * r << endl;
    return 0;
}
