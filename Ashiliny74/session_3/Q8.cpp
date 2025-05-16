#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

string findThirdLargestString(const vector<string>& arr) {
    // Use a set to store unique lengths
    set<int> lengths;

    // Populate the set with the lengths of the strings
    for (const string& str : arr) {
        lengths.insert(str.length());
    }

    // Check if there are at least three unique lengths
    if (lengths.size() < 3) {
        return "Not enough unique lengths";
    }

    // Create an iterator to find the third largest length
    auto it = lengths.rbegin(); // Start from the largest
    advance(it, 2); // Move to the third largest

    int thirdLargestLength = *it;

    // Find the first string with the third largest length
    for (const string& str : arr) {
        if (str.length() == thirdLargestLength) {
            return str;
        }
    }

    return "Not found"; // This should not happen if the logic is correct
}

int main() {
    // Sample arrays
    vector<string> arr1 = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    vector<string> arr2 = {"abc", "abc", "abc", "abc", "abc"};
    vector<string> arr3 = {"abcd", "abcd", "abc"};

    cout << "Array elements: ";
    for (const string ⬤