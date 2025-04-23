#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compareByLength(const string& a, const string& b) {
    return a.length() > b.length();
}

string findThirdLargestString(vector<string> arr) {
   
    set<string> uniqueSet(arr.begin(), arr.end());
    vector<string> uniqueArr(uniqueSet.begin(), uniqueSet.end());

    sort(uniqueArr.begin(), uniqueArr.end(), compareByLength);

    if (uniqueArr.size() < 3) {
        return uniqueArr.back();
    }

    return uniqueArr[2]; 
}

int main() {
    vector<vector<string>> testCases = {
        {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"},
        {"abc", "abc", "abc", "abc", "abc"},
        {"abcd", "abcd", "abc"}
    };

    for (auto& arr : testCases) {
        cout << "Array elements: ";
        for (auto& str : arr)
            cout << str << " ";
        cout << "\nThird highest length string: " << findThirdLargestString(arr) << "\n\n";
    }

    return 0;
}

