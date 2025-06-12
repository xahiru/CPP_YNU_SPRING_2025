#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14159 * radius * radius; }
    double perimeter() override { return 2 * 3.14159 * radius; }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override { return length * width; }
    double perimeter() override { return 2 * (length + width); }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    
    for (Shape* s : shapes) {
        cout << "Area: " << s->area() << ", Perimeter: " << s->perimeter() << endl;
        delete s;
    }
    return 0;
}