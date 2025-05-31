#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string findThirdLargestString(const vector<string>& arr) {
    // Use a set to store unique lengths in descending order
    set<int, greater<int>> uniqueLengths;
    
    for (const auto& str : arr) {
        uniqueLengths.insert(str.length());
    }

    // If there are fewer than 3 unique lengths
    if (uniqueLengths.size() < 3) {
        // Return the smallest length string found
        int targetLength = *uniqueLengths.rbegin();
        for (const auto& str : arr) {
            if (str.length() == targetLength)
                return str;
        }
    } else {
        // Find the third largest length
        auto it = uniqueLengths.begin();
        advance(it, 2);
        int thirdLargestLength = *it;

    
        for (const auto& str : arr) {
            if (str.length() == thirdLargestLength)
                return str;
        }
    }

    return "";
}

int main() {
    vector<vector<string>> testArrays = {
        {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"},
        {"abc", "abc", "abc", "abc", "abc"},
        {"abcd", "abcd", "abc"}
    };

    for (const auto& arr : testArrays) {
        cout << "Array elements: ";
        for (const auto& s : arr)
            cout << s << " ";
        cout << "\nThird highest length string: " << findThirdLargestString(arr) << "\n\n";
    }

    return 0;
}
