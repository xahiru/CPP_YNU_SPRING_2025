#include <iostream>
#include <cmath>
using namespace std;

// Base Shape class with virtual functions
class Shape {
public:
    // Virtual functions to be overridden by derived classes
    virtual double calculateArea() const = 0;  // Pure virtual function
    virtual double calculatePerimeter() const = 0;  // Pure virtual function
    virtual void display() const {
        cout << "This is a generic shape." << endl;
    }
    
    // Virtual destructor
    virtual ~Shape() {}
};

// Derived Circle class
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.141592653589793;

public:
    Circle(double r = 0.0) : radius(r) {
        if (r < 0) {
            radius = 0;
            cout << "Invalid radius. Setting to 0." << endl;
        }
    }

    double calculateArea() const override {
        return PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }

    void display() const override {
        cout << "Circle with radius " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Circumference: " << calculatePerimeter() << endl;
    }
};

// Derived Rectangle class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0.0, double w = 0.0) : length(l), width(w) {
        if (l < 0 || w < 0) {
            length = width = 0;
            cout << "Invalid dimensions. Setting to 0." << endl;
        }
    }

    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }

    void display() const override {
        cout << "Rectangle with length " << length 
             << " and width " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

// Derived Triangle class
class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1 = 0.0, double s2 = 0.0, double s3 = 0.0) 
        : side1(s1), side2(s2), side3(s3) {
        if (s1 < 0 || s2 < 0 || s3 < 0) {
            side1 = side2 = side3 = 0;
            cout << "Invalid sides. Setting to 0." << endl;
        }
    }

    double calculateArea() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }

    void display() const override {
        cout << "Triangle with sides " << side1 << ", " 
             << side2 << ", " << side3 << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Create an array of Shape pointers
    Shape* shapes[3];
    
    // Initialize with different derived class objects
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 4.0, 5.0);

    // Demonstrate polymorphism
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "------------------------" << endl;
    }

    // Clean up memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}