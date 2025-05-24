#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinaryStrings(string str1, string str2) {
    int i = str1.length() - 1;
    int j = str2.length() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += str1[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += str2[j] - '0'; 
            j--;
        }

        result += (sum % 2) + '0';  
        carry = sum / 2; 
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string binary1, binary2;

    cout << "Enter the first binary number: ";
    cin >> binary1;
    cout << "Enter the second binary number: ";
    cin >> binary2;

    string result = addBinaryStrings(binary1, binary2);

    cout << "Sum of binary numbers: " << result << endl;

    return 0;
}