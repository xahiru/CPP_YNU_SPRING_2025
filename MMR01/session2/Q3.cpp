#include <iostream>
using namespace std;

int main() {
    double length, width;

    cout << "Find the Area and Perimeter of a Rectangle \n";
    
    // Input length and width
    cout << "Input the length of the rectangle : ";
    cin >> length;
    cout << "Input the width of the rectangle : ";
    cin >> width;

    // Calculate Area (A = length × width)
    double area = length * width;
    
    // Calculate Perimeter (P = 2 × (length + width))
    double perimeter = 2 * (length + width);

    // Display results
    cout << "The area of the rectangle is : " << area << endl;
    cout << "The perimeter of the rectangle is : " << perimeter << endl;

    return 0;
}