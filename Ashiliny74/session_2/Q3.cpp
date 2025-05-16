#include <iostream>
using namespace std;

int main() {
    double length, width;

    // Input length and width
    cout << "Find the Area and Perimeter of a Rectangle :" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Input the length of the rectangle : ";
    cin >> length;
    cout << "Input the width of the rectangle : ";
    cin >> width;

    // Calculate area and perimeter
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Output the results
    cout << "The area of the rectangle is : " << area << endl;
    cout << "The perimeter of the rectangle is : " << perimeter << endl;

    return 0;
}
