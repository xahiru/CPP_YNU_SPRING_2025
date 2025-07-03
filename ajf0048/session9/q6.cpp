#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() override {
        return length * width;
    }

    double getPerimeter() override {
        return 2 * (length + width);
    }
};

int main() {
    Circle circle(5.0);
    cout << "Circle Area: " << circle.getArea() << endl;
    cout << "Circle Perimeter: " << circle.getPerimeter() << endl;

    Rectangle rectangle(4.0, 5.0);
    cout << "Rectangle Area: " << rectangle.getArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.getPerimeter() << endl;

    return 0;
}