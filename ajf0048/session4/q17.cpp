#include <iostream>
#include <string>
using namespace std;

string addBinary(const string& a, const string& b) {
    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    // Loop until both strings are processed and there's no carry left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; // Start with the carry

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
        result += (sum % 2) + '0'; // Append the result digit
        carry = sum / 2; // Update carry
    }

    // Manually reverse the result string
    string finalResult;
    for (int k = result.size() - 1; k >= 0; k--) {
        finalResult += result[k];
    }

    return finalResult;
}

int main() {
    string str1 = "101011"; // First binary string
    string str2 = "1101";   // Second binary string
    string result = addBinary(str1, str2);

    cout << "Binary Number = " << result << endl; // Output the result

    return 0;
}
