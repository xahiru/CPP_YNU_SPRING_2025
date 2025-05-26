#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        if (r > 0) {
            radius = r;
        } else {
            radius = 0;
            cout << "Invalid radius. Setting radius to 0." << endl;
        }
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }

    double calculateCircumference() const {
        return 2 * M_PI * radius;
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            cout << "Invalid radius. Radius must be positive." << endl;
        }
    }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    Circle myCircle(r);

    cout << "\nCircle Details:" << endl;
    cout << "Radius: " << myCircle.getRadius() << endl;
    cout << "Area: " << myCircle.calculateArea() << endl;
    cout << "Circumference: " << myCircle.calculateCircumference() << endl;

    return 0;
}