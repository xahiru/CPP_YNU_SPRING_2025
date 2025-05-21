#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addBinaryStrings(string a, string b) {
    string result;
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 2;
        result.push_back(sum % 2 + '0');
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string binary1, binary2;
    
    cout << "Enter first binary number: ";
    cin >> binary1;
    
    cout << "Enter second binary number: ";
    cin >> binary2;
    
    string sum = addBinaryStrings(binary1, binary2);
    
    cout << "Sum of " << binary1 << " and " << binary2 
         << " is: " << sum << endl;
    
    return 0;
}