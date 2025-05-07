#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Test cases 
    vector<vector<string>> tests = {
        {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"},
        {"abc", "abc", "abc", "abc", "abc"},
        {"abcd", "abcd", "abc"}
    };

    for (auto& arr : tests) {  // Loop through each test case
        cout << "Array elements: ";
        for (auto& s : arr) cout << s << " ";  // Print original array
        
        // Sort by length (descending) using lambda comparator
        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            return a.size() > b.size();
        });
        
        // Find third distinct length
        int distinct = 1;
        string result = arr[0];  // Default to first (longest)
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i].size() != arr[i-1].size() && ++distinct == 3) {
                result = arr[i];
                break;
            }
        }
        
        cout << "\nThird highest length string: " << result << "\n\n";
    }
}