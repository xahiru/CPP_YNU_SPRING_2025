#include <iostream>
#include <string>
#include <cmath> // For pow function
using namespace std;

// Function to convert binary string to decimal
int binaryToDecimal(const string& binary) {
    int decimalValue = 0;
    int length = binary.length();

    // Iterate over each bit in the binary string
    for (int i = 0; i < length; i++) {
        // Convert the character to an integer (0 or 1)
        int bit = binary[length - 1 - i] - '0'; // Get the bit from the end
        decimalValue += bit * pow(2, i); // Add the corresponding decimal value
    }

    return decimalValue;
}

int main() {
    // Input binary string
    string binary;

    cout << "Enter a binary number: ";
    cin >> binary;

    // Convert binary to decimal
    int decimalValue = binaryToDecimal(binary);

    // Output the result
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}