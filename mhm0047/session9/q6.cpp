#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    double perimeter() const override { return 2 * 3.14159 * radius; }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    double perimeter() const override { return 2 * (length + width); }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Triangle(3.0, 4.0, 5.0)
    };

    for (Shape* shape : shapes) {
        cout << "Area: " << shape->area() 
             << ", Perimeter: " << shape->perimeter() << endl;
        delete shape;
    }
    return 0;
}