#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result;
    int i = a.length() - 1, j = b.length() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0';
        if (j >= 0) carry += b[j--] - '0';
        result += (carry % 2) + '0';
        carry /= 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "1010", b = "1011";
    cout << addBinary(a, b) << endl;
    return 0;
}