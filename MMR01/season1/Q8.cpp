#include <iostream>
#include <algorithm> // for max() function
using namespace std;

int main() {
    float a, b, c; //Declares three floating-point variables to store the user's input numbers.

    cout << "Enter three numbers: "; //Prompts the user to enter three numbers.
    cin >> a >> b >> c; //Reads the three input numbers and stores them in variables a, b, and c.

    float largest = max(a, max(b, c));
    cout << "Largest number: " << largest; //Outputs the largest number to the console.

    return 0;
}