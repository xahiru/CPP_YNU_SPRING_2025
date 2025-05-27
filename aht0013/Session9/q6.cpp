#include <iostream>
#include <cmath>
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
        return M_PI * radius * radius;
    }
    double getPerimeter() override {
        return 2 * M_PI * radius;
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

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    double getArea() override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double getPerimeter() override {
        return side1 + side2 + side3;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 4.0, 5.0);
    
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << i+1 << " - Area: " << shapes[i]->getArea();
        cout << ", Perimeter: " << shapes[i]->getPerimeter() << endl;
        delete shapes[i];
    }
    
    return 0;
}





