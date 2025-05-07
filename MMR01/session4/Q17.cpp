#include <iostream>
#include <string>
#include <algorithm> // Include the algorithm library for reverse
using namespace std;

// Function to add two binary strings
string addBinaryStrings(const string& a, const string& b) {
    string result; 
    int carry = 0; 

    int i = a.size() - 1;
    int j = b.size() - 1;

    // Loop until both strings are processed
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; // Start with carry

        // Add the current bit of a if available
        if (i >= 0) {
            sum += a[i] - '0'; // Convert char to int
            i--;
        }

        // Add the current bit of b if available
        if (j >= 0) {
            sum += b[j] - '0'; // Convert char to int
            j--;
        }

        // Calculate the result bit and the new carry
        result.push_back((sum % 2) + '0'); // Append the result bit
        carry = sum / 2; // Update carry
    }

    // The result is in reverse order, so reverse it
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // Input binary strings
    string binary1 = "101011";
    string binary2 = "1101";

    // Add the binary strings
    string result = addBinaryStrings(binary1, binary2);

    // Output the result
    cout << "Binary Number 1: " << binary1 << endl;
    cout << "Binary Number 2: " << binary2 << endl;
    cout << "Sum: " << result << endl;

    return 0;
}