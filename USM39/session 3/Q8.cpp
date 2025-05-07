#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string findThirdLargestString(vector<string> arr) {
    if (arr.size() < 3) {
        return arr.back();
    }
    
    sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        return a.length() > b.length();
    });
    
    int count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].length() < arr[i-1].length()) {
            count++;
            if (count == 3) {
                return arr[i];
            }
        }
    }
    
    return arr.back();
}

int main() {
    vector<string> arr1 = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    vector<string> arr2 = {"abc", "abc", "abc", "abc", "abc"};
    vector<string> arr3 = {"abcd", "abcd", "abc"};
    
    cout << "Array elements: ";
    for (string s : arr1) cout << s << " ";
    cout << endl << "Third highest length string: " << findThirdLargestString(arr1) << endl;
    
    cout << "\nArray elements: ";
    for (string s : arr2) cout << s << " ";
    cout << endl << "Third highest length string: " << findThirdLargestString(arr2) << endl;
    
    cout << "\nArray elements: ";
    for (string s : arr3) cout << s << " ";
    cout << endl << "Third highest length string: " << findThirdLargestString(arr3) << endl;
    
    return 0;
}