#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;


    int lengthDiff = a.length() - b.length();
    if (lengthDiff > 0) {
        b = string(lengthDiff, '0') + b;
    } else if (lengthDiff < 0) {
        a = string(-lengthDiff, '0') + a;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        int bit1 = a[i] - '0';
        int bit2 = b[i] - '0';
        int sum = bit1 + bit2 + carry;

        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) {
        result += '1';
    }


    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string str1 = "101011";
    string str2 = "1101";

    cout << "Binary Number 1 = " << str1 << endl;
    cout << "Binary Number 2 = " << str2 << endl;

    string sum = addBinary(str1, str2);
    cout << "Sum = " << sum << endl;

    return 0;
}
