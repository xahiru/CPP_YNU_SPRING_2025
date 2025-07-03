#include <iostream>
#include <vector>
#include <string>
#includes <cctype> 

using namespace std;

bool containsNumber(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) { 
            return true; 
        }
    }
    return false; 
}

vector<string> filterStringsWithNumbers(const vector<string>& vec) {
    vector<string> result;
    for (const string& str : vec) {
        if (containsNumber(str)) {
            result.push_back(str); 
        }
    }
    return result; 
}

int main() {

    vector<string> vec = {"red", "green23", "1black", "white"};

    vector<string> result = filterStringsWithNumbers(vec);

    cout << "Strings containing numbers: ";
    if (result.empty()) {
        cout << "None" << endl; 
    } else {
        for (const string& str : result) {
            cout << str << " "; 
        }
        cout << endl;
    }

    return 0;
}