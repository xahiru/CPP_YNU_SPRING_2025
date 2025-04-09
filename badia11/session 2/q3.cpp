#include <iostream>
using namespace std;

int main() {
    int length, width, area, perimeter;

    cout << "Find the Area and Perimeter of a Rectangle:\n";
    cout << "-------------------------------------------\n";
    cout << "Input the length of the rectangle: ";
    cin >> length;
    cout << "Input the width of the rectangle: ";
    cin >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    cout << "The area of the rectangle is:
    
    