#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> filterStringsWithNumbers(const vector<string>& strings) {
    vector<string> result;
    for (const string& str : strings) {
        for (char c : str) {
            if (isdigit(c)) {
                result.push_back(str);
                break;
            }
        }
    }


    return result;
}

int main() {
    vector<string> input;
    int n;
    string str;
    
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // Clear the input buffer
    
    cout << "Enter " << n << " strings (one per line):" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        input.push_back(str);
    }
    
    vector<string> output = filterStringsWithNumbers(input);
    
    cout << "\nStrings containing numbers: ";
    if (output.empty()) {
        cout << "None found";
    } else {
        for (const string& s : output) {
            cout << s << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}