#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() override { return M_PI*r*r; }
    double perimeter() override { return 2*M_PI*r; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double length, double width) : l(length), w(width) {}
    double area() override { return l*w; }
    double perimeter() override { return 2*(l+w); }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
    double area() override {
        double s = perimeter()/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double perimeter() override { return a+b+c; }
};

int main() {
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4,6),
        new Triangle(3,4,5)
    };
    
    for(auto s : shapes) {
        cout << "Area: " << s->area() 
             << ", Perimeter: " << s->perimeter() << endl;
        delete s;
    }
}