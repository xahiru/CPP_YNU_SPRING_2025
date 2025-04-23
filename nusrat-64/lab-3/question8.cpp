#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> arr = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    
    cout << "Array elements: ";
    for (const string& str : arr) {
        cout << str << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    if (arr.size() >= 3) {
        cout << "Third highest length string: " << arr[2] << endl;
    } else {
        cout << "Not enough elements in the array!" << endl;
    }

    return 0;
}