#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// Q1: Volume of a Sphere
double calculateSphereVolume(double radius) {
    return (4.0/3.0) * M_PI * pow(radius, 3);
}

// Q2: Volume of a Cube
double calculateCubeVolume(double side) {
    return pow(side, 3);
}

// Q3: Area and Perimeter of Rectangle
void calculateRectangleProperties(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

// Q4: Area and Circumference of Circle
void calculateCircleProperties(double radius, double &area, double &circumference) {
    area = M_PI * pow(radius, 2);
    circumference = 2 * M_PI * radius;
}

// Q5: Print numbers in word (1-9)
string numberToWord(int number) {
    const string words[] = {"", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};
    return (number >= 1 && number <= 9) ? words[number] : "";
}

// Q6: Print numbers and check even/odd
string numberDescription(int number) {
    string word = numberToWord(number);
    if (!word.empty()) return word;
    return (number % 2 == 0) ? "even" : "odd";
}

// Main function to demonstrate all solutions
int main() {
    cout << "==== Geometry and Number Utilities ====\n";
    
    // Q1: Sphere Volume
    double sphereVol = calculateSphereVolume(5.0);
    cout << "Q1: Sphere volume (r=5) = " << sphereVol << " cubic units\n";
    
    // Q2: Cube Volume
    double cubeVol = calculateCubeVolume(4.0);
    cout << "Q2: Cube volume (side=4) = " << cubeVol << " cubic units\n";
    
    // Q3: Rectangle Properties
    double rectArea, rectPerimeter;
    calculateRectangleProperties(10.0, 15.0, rectArea, rectPerimeter);
    cout << "Q3: Rectangle (10x15) - Area: " << rectArea 
         << ", Perimeter: " << rectPerimeter << endl;
    
    // Q4: Circle Properties
    double circleArea, circleCircum;
    calculateCircleProperties(5.0, circleArea, circleCircum);
    cout << "Q4: Circle (r=5) - Area: " << circleArea 
         << ", Circumference: " << circleCircum << endl;
    
    // Q5: Number to Word
    cout << "Q5: Number to Word:\n";
    for (int i = 0; i <= 10; i++) {
        string word = numberToWord(i);
        if (!word.empty()) cout << i << " = " << word << endl;
    }
    
    // Q6: Number Descriptions
    cout << "Q6: Number Descriptions (8-11):\n";
    for (int i = 8; i <= 11; i++) {
        cout << i << " = " << numberDescription(i) << endl;
    }
    
    return 0;
}