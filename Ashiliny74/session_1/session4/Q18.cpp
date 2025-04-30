#include <iostream>
#include <string>
#include <cmath> // For pow function
using namespace std;

// Function to convert binary string to decimal
int binaryToDecimal(const string& binary) {
    int decimal = 0; // Initialize decimal result
    int length = binary.length(); // Get the length of the binary string

    // Iterate through each digit in the binary string
    for (int i = 0; i < length; ++i) {
        // Convert character to integer and calculate the decimal value
        if (binary[length - 1 - i] == '1') {
            decimal += pow(2, i); // Add 2^i if the digit is '1'
        }
    }

    return decimal; // Return the decimal result
}

int main() {
    // Input binary string
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    // Print the result
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
\