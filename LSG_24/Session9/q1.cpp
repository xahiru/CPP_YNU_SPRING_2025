#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    void setRadius(double r) {
        radius = r;
    }
    double getArea() {
        return 3.14159 * radius * radius;
    }
    double getCircumference() {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    Circle c;
    c.setRadius(5.0);
    cout << "Area: " << c.getArea() << endl;
    cout << "Circumference: " << c.getCircumference() << endl;
    return 0;
}