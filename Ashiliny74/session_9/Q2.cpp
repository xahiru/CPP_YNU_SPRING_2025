#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;
public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }
    double getArea() {
        return length * width;
    }
    double getPerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r;
    r.setDimensions(4.0, 6.0);
    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;
    return 0;
}