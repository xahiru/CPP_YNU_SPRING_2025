#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string findThirdLargestString(vector<string> arr) {
    if (arr.size() < 3) return arr.back();
    
    sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        return a.length() > b.length();
    });
    
    // Find the third distinct length
    int distinct = 1;
    int thirdLen = arr[0].length();
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i].length() != thirdLen) {
            distinct++;
            thirdLen = arr[i].length();
            if (distinct == 3) break;
        }
    }
    
    if (distinct < 3) return arr.back();
    
    for (const string &s : arr) {
        if (s.length() == thirdLen) return s;
    }
    
    return "";
}

int main() {
    vector<string> arr1 = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    vector<string> arr2 = {"abc", "abc", "abc", "abc", "abc"};
    vector<string> arr3 = {"abcd", "abcd", "abc"};
    
    cout << "Third highest length string: " << findThirdLargestString(arr1) << endl;
    cout << "Third highest length string: " << findThirdLargestString(arr2) << endl;
    cout << "Third highest length string: " << findThirdLargestString(arr3) << endl;
    
    return 0;
}