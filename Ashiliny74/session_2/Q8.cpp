#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// Function declarations
void calculateSphereVolume();
void calculateCubeVolume();
void calculateRectangleAreaAndPerimeter();
void calculateCircleAreaAndCircumference();
void printNumberInWords(int n);
void printNumbersAndCheckEvenOdd(int a, int b);

int main() {
    // Sample calls to each function
    calculateSphereVolume();
    calculateCubeVolume();
    calculateRectangleAreaAndPerimeter();
    calculateCircleAreaAndCircumference();

    int a, b;
    cout << "Enter two positive integers (a and b): ";
    cin >> a >> b;
    printNumbersAndCheckEvenOdd(a, b);

    return 0;
}

// Function definitions
void calculateSphereVolume() {
    cout << "Calculate the volume of a sphere:\n";
    cout << "---------------------------------------\n";
    double radius;
    cout << "Input the radius of a sphere: ";
    cin >> radius;
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    cout << "The volume of a sphere is : " << setprecision(5) << fixed << volume << endl;
}

void calculateCubeVolume() {
    cout << "\nCalculate the volume of a cube:\n";
    cout << "---------------------------------\n";
    double side;
    cout << "Input the side of a cube: ";
    cin >> side;
    double volume = pow(side, 3);
    cout << "The volume of a cube is : " << volume << endl;
}

void calculateRectangleAreaAndPerimeter() {
    cout << "\nFind the Area and Perimeter of a Rectangle:\n";
    cout << "---------------------------------------------\n";
    double length, width;
    cout << "Input the length of the rectangle: ";
    cin >> length;
    cout << "Input the width of the rectangle: ";
    cin >> width;
    double area = length * width;
    double perimeter = 2 * (length + width);
    cout << "The area of the rectangle is : " << area << endl;
    cout << "The perimeter of the rectangle is : " << perimeter << endl;
}

void calculateCircleAreaAndCircumference() {
    cout << "\nFind the area and circumference of any circle:\n";
    cout << "------------------------------------------------\n";
    double radius;
    cout << "Input the radius (1/2 of diameter) of a circle: ";
    cin >> radius;
    double area = M_PI * pow(radius, 2);
    double circumference = 2 * M_PI * radius;
    cout << "The area of the circle is : " << setprecision(5) << fixed << area << endl;
    cout << "The circumference of the circle is : " << setprecision(5) << fixed << circumference << endl;
}

void printNumberInWords(int n) {
    string words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n > 1 && n < 9) {
        cout << words[n] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }
}

void printNumbersAndCheckEvenOdd(int a, int b) {
    for (int n = a; n <= b; ++n) {
        if (1 <= n && n <= 9) {
            printNumberInWords(n);
        } else if (n > 9) {
            if (n % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }
}