#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Volume of a Sphere
double sphereVolume(double radius) {
    const double PI = 3.14;
    return (4.0/3.0) * PI * pow(radius, 3);
}

// olume of a Cube
double cubeVolume(double side) {
    return pow(side, 3);
}

// Area and Circumference of Circle
void circleProperties(double radius, double& area, double& circumference) {
    const double PI = 3.14159265358979323846;
    area = PI * pow(radius, 2);
    circumference = 2 * PI * radius;
}

// Number to Word (1-9)
string numberToWord(int n) {
    string words[] = {"", "one", "two", "three", "four", 
                     "five", "six", "seven", "eight", "nine"};
    if (n >= 1 && n <= 9) return words[n];
    return "";
}

// Number Range with Even/Odd Check
void processNumberRange(int a, int b) {
    for (int n = a; n <= b; n++) {
        if (n >= 1 && n <= 9) {
            cout << numberToWord(n) << endl;
        } else {
            cout << (n % 2 == 0 ? "even" : "odd") << endl;
        }
    }
}

// Maximum of Four Numbers
int max_of_four(int a, int b, int c, int d) {
    return max({a, b, c, d});
}

int main() {
    // Sphere Volume
    cout << "Q1: Sphere Volume (radius=6): " << sphereVolume(6) << endl;

    // Cube Volume
    cout << "Q2: Cube Volume (side=5): " << cubeVolume(5) << endl;

    // Circle Properties
    double radius = 5, area, circumference;
    circleProperties(radius, area, circumference);
    cout << "Q3: Circle Properties (radius=5):\n"
         << "Area: " << area << "\nCircumference: " << circumference << endl;

    // Number to Word
    cout << "Q4: Number to Word (5): " << numberToWord(5) << endl;

    // Number Range Processing
    cout << "Q5: Process Range (8-11):\n";
    processNumberRange(8, 11);

    // Max of Four
    cout << "Q6: Max of Four (3,4,6,5): " << max_of_four(3,4,6,5) << endl;

    return 0;
}