#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<string>> testCases = {
        {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"},
        {"abc", "abc", "abc", "abc", "abc"},
        {"abcd", "abcd", "abc"}
    };

    for (auto& arr : testCases) {
        cout << "Array elements: ";
        for (const auto& s : arr) {
            cout << s << " ";
        }
        cout << endl;

        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j].length() < arr[j+1].length()) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }

        int distinctCount = 1;        //finding the thrid distinct length
        size_t currentLength = arr[0].length(); //if length less than 3 disnict length return to defualt
        string result = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i].length() != currentLength) {
                currentLength = arr[i].length();
                distinctCount++;
                
                if (distinctCount == 3) {
                    result = arr[i];
                    break;
                }
            }
        }

        if (distinctCount < 3) {
            result = arr.back();
        }

        cout << "Third highest length string: " << result << endl << endl;
    }


    return 0;
}