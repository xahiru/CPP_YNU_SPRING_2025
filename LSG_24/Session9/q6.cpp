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
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    
    for (Shape* shape : shapes) {
        cout << "Area: " << shape->getArea() << endl;
        cout << "Perimeter: " << shape->getPerimeter() << endl;
    }
    
    delete shapes[0];
    delete shapes[1];
    return 0;
}