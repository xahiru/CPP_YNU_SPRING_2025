#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string findThirdLargestString(const vector<string>& arr) {

    set<int, greater<int>> lengths; 

    for (const string& str : arr) {
        lengths.insert(str.size());
    }

    if (lengths.size() < 3) {
        return "Not enough unique lengths";  
    }

    auto it = lengths.begin();
    advance(it, 2);  

    int thirdLargestLength = *it;

    for (const string& str : arr) {
        if (str.size() == thirdLargestLength) {
            return str;
        }
    }

    return ""; 
}

int main() {

    vector<string> arr1 = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    cout << "Array elements: ";
    for (const string& str : arr1) {
        cout << str << " ";
    }
    cout << endl;
    cout << "Third highest length string: " << findThirdLargestString(arr1) << endl;

    vector<string> arr2 = {"abc", "abc", "abc", "abc", "abc"};
    cout << "Array elements: ";
    for (const string& str : arr2) {
        cout << str << " ";
    }
    cout << endl;
    cout << "Third highest length string: " << findThirdLargestString(arr2) << endl;

    vector<string> arr3 = {"abcd", "abcd", "abc"};
    cout << "Array elements: ";
    for (const string& str : arr3) {
        cout << str << " ";
    }
    cout << endl;
    cout << "Third highest length string: " << findThirdLargestString(arr3) << endl;

    return 0;
}
