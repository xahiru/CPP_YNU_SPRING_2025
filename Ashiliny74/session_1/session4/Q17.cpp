#include <iostream>
#include <string>
using namespace std;

// Function to add two binary strings
string addBinaryStrings(const string& a, const string& b) {
    string result; // To store the result
    int carry = 0; // To store carry
    int i = a.size() - 1; // Pointer for string a
    int j = b.size() - 1; // Pointer for string b

    // Loop until both strings are processed
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; // Start with carry

        // Add the current digit of a if available
        if (i >= 0) {
            sum += a[i] - '0'; // Convert char to int
            i--;
        }

        // Add the current digit of b if available
        if (j >= 0) {
            sum += b[j] - '0'; // Convert char to int
            j--;
        }

        // Calculate the result digit and the new carry
        result.push_back((sum % 2) + '0'); // Append the result digit
        carry = sum / 2; // Update carry
    }

    // The result is in reverse order, so reverse it
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // Define two binary strings
    string binary1 = "101011";
    string binary2 = "1101";

    // Print the binary numbers
    cout << "Binary Number 1 = " << binary1 << endl;
    cout << "Binary Number 2 = " << binary2 << endl;

    // Add the binary strings
    string sum = addBinaryStrings(binary1, binary2);

    // Print the result
    cout << "Sum = " << sum << endl;

    return 0;
}