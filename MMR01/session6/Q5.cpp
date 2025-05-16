#include <iostream>
#include <string>
using namespace std;

string reverseString(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main() {
    // Test cases
    cout << reverseString("Hello") << endl;  
    cout << reverseString("World") << endl; 
    return 0;
}