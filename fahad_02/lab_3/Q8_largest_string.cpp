#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareLength(const string &a, const string &b) {
    return a.length() > b.length(); 
}

string findThirdLargestString(vector<string> &arr) {
    sort(arr.begin(), arr.end(), compareLength);

    int count = 1;
    int currentLength = arr[0].length();

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i].length() != currentLength) {
            count++;
            currentLength = arr[i].length();
        }

        if (count == 3) {
            return arr[i];
        }
    }

    return arr.back();
}

int main() {
    vector<vector<string>> testArrays = {
        {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"},
        {"abc", "abc", "abc", "abc", "abc"},
        {"abcd", "abcd", "abc"}
    };

    for (auto &arr : testArrays) {
        cout << "Array elements: ";
        for (auto &str : arr) {
            cout << str << " ";
        }

        string third = findThirdLargestString(arr);
        cout << "\nThird highest length string: " << third << "\n\n";
    }

    return 0;
}
