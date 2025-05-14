#include <iostream>
#include <string>
using namespace std;

void printSubstring(const string &s, int L, int R) {
    // Check if L and R are within valid bounds
    if (L < 0 || R >= s.length() || L > R) {
        cout << "Invalid indices" << endl;
        return;
    }
    // Extract and print the substring from L to R inclusive
    cout << s.substr(L, R - L + 1) << endl;
}

int main() {
    // Test cases
    printSubstring("cdbkdub", 0, 5);       
    printSubstring("sdiblcsdbud", 3, 7);   
    return 0;
}