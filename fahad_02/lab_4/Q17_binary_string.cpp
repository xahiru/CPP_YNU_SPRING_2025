#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string addBinary(string a, string b) {
    string result;
    int i = a.length() - 1, j = b.length() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result.push_back(sum % 2 + '0');
        carry = sum / 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string binary1 = "1010";
    string binary2 = "1011";
    
    cout << "Binary 1: " << binary1 << endl;
    cout << "Binary 2: " << binary2 << endl;
    cout << "Sum: " << addBinary(binary1, binary2) << endl;
    
    return 0;
}