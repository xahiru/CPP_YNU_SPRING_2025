#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string thirdLargestString(vector<string> arr) {
    sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        return a.size() > b.size();
    });
    return arr[2];
}

int main() {
    vector<string> arr1 = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    cout << "Third highest length string: " << thirdLargestString(arr1) << endl;

    vector<string> arr2 = {"abc", "abc", "abc", "abc", "abc"};
    cout << "Third highest length string: " << thirdLargestString(arr2) << endl;

    vector<string> arr3 = {"abcd", "abcd", "abc"};
    cout << "Third highest length string: " << thirdLargestString(arr3) << endl;

    return 0;
}