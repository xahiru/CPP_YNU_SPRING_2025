#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string binarySum(const string& bin1, const string& bin2) {
    int i = bin1.size() - 1;
    int j = bin2.size() - 1;
    int sum = 0, carry = 0;
    string output = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int bitA = (i >= 0) ? bin1[i--] - '0' : 0;
        int bitB = (j >= 0) ? bin2[j--] - '0' : 0;

        sum = bitA + bitB + carry;
        output += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    string binStr1 = "1010";
    string binStr2 = "1011";

    string result = binarySum(binStr1, binStr2);
    cout << "Result: " << result << endl;

    return 0;
}
