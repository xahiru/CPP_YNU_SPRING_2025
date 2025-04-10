#include <iostream>
using namespace std;

void rectangleAreaAndPerimeter(double length, double width) {
    double area = length * width;
    double perimeter = 2 * (length + width);
    cout << "The area of the rectangle is : " << area << endl;
    cout << "The perimeter of the rectangle is : " << perimeter << endl;
}

int main() {
    double length, width;
    cout << "Find the Area and Perimeter of a Rectangle :" << endl;
    cout << "Input the length of the rectangle : ";
    cin >> length;
    cout << "Input the width of the rectangle : ";
    cin >> width;
    rectangleAreaAndPerimeter(length, width);
    return 0;
}