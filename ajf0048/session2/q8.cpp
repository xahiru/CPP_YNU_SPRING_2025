#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the volume of a sphere
double volumeOfSphere(double r, double PI = 3.14) {
    return (4.0 / 3.0) * PI * pow(r, 3);
}

// Function to calculate the volume of a cube
double volumeOfCube(double r) {
    return (r*r*r);
}

// Function to calculate the area and perimeter of a rectangle
void rectangleAreaAndPerimeter(double length, double width) {
    double area = length * width;
    double perimeter = 2 * (length + width);
    cout << "The area of the rectangle is : " << area << endl;
    cout << "The perimeter of the rectangle is : " << perimeter << endl;
}

// Function to calculate the area and circumference of a circle
void circleAreaAndCircumference(double r, double PI = 3.14) {
    double area = PI * (r*r);
    double circumference = 2 *PI * r;
    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << circumference << endl;
}

// Function to print numbers in word
string numberToWord(int n) {
    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight"};
    if (n >= 0 && n <= 8) {
        return words[n];
    } else {
        return "Greater than 9";
    }
}

// Function to check if a number is even or odd
void checkEvenOrOdd(int number) {
    cout << number << " is ";
    if (number % 2 == 0) {
        cout << "even." << endl;
    } else {
        cout << "odd." << endl;
    }
}

int main() {
    double sphereRadius;
    cout << "Calculate the volume of a sphere :" << endl;
    cout << "---------------------------" << endl;
    cout << "Input the radius of a sphere : ";
    cin >> sphereRadius;
    cout << "The volume of a sphere is : " << volumeOfSphere(sphereRadius) << endl;

    double cubeSide;
    cout << "\nCalculate the volume of a cube :" << endl;
    cout << "---------------------------" << endl;
    cout << "Input the side of a cube : ";
    cin >> cubeSide;
    cout << "The volume of a cube is : " << volumeOfCube(cubeSide) << endl;

    double rectLength, rectWidth;
    cout << "\nFind the Area and Perimeter of a Rectangle :" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Input the length of the rectangle : ";
    cin >> rectLength;
    cout << "Input the width of the rectangle : ";
    cin >> rectWidth;
    rectangleAreaAndPerimeter(rectLength, rectWidth);

    double circleRadius;
    cout << "\nFind the area and circumference of any circle :" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Input the radius(1/2 of diameter) of a circle : ";
    cin >> circleRadius;
    circleAreaAndCircumference(circleRadius);

    int numberInWord;
    cout << "\nEnter a number between 0 and 8 to print in words: ";
    cin >> numberInWord;
    cout << numberInWord << " in words is: " << numberToWord(numberInWord) << endl;

    int numberCheck;
    cout << "\nEnter a number to check if it's even or odd: ";
    cin >> numberCheck;
    checkEvenOrOdd(numberCheck);

    return 0;
}