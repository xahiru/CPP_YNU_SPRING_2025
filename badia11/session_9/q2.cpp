#include <iostream>
using namespace std;

class Rectangle {
private:
    float length, width;
public:
    void setDimensions(float l, float w) {
        length = l;
        width = w;
    }
    float getArea() {
        return length * width;
    }
    float getPerimeter() {
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
