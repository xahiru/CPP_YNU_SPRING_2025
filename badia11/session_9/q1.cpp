#include <iostream>
using namespace std;

class Circle {
private:
    float radius;
public:
    void setRadius(float r) {
        radius = r;
    }
    float getArea() {
        return 3.14159 * radius * radius;
    }
    float getCircumference() {
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
