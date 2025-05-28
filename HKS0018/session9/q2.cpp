#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
    double getLength() {
        return length;
    }
    double getWidth() {
        return width;
    }
};

int main() {
    double length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    Rectangle myRectangle(length, width);

    cout << "Area of the rectangle: " << myRectangle.calculateArea() << endl;
    cout << "Perimeter of the rectangle: " << myRectangle.calculatePerimeter() << endl;

    
    return 0;

}