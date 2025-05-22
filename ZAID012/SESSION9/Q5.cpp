#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return M_PI * radius * radius;
    }
    
    double perimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    double area() override {
        return length * width;
    }
    
    double perimeter() override {
        return 2 * (length + width);
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 5);
    
    cout << "Circle Area: " << circle.area() << ", Perimeter: " << circle.perimeter() << endl;
    cout << "Rectangle Area: " << rectangle.area() << ", Perimeter: " << rectangle.perimeter() << endl;
    return 0;
}
