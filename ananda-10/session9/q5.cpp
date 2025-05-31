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
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}

    double area() const override {
        double s = (a + b + c) / 2; 
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }

    double perimeter() const override {
        return a + b + c;
    }
};

int main() {
    Shape* shape;

    shape = new Circle(5.0);
    cout << "Circle:\n";
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;
    delete shape;

    shape = new Rectangle(4.0, 6.0);
    cout << "\nRectangle:\n";
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;
    delete shape;

    shape = new Triangle(3.0, 4.0, 5.0);
    cout << "\nTriangle:\n";
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;
    delete shape;

    return 0;
}

