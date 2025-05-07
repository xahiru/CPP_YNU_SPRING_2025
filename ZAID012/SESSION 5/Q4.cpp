#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> capitalizeFirstLetter(const vector<string>& vec) {
    vector<string> result;
    for (const string& str : vec) {
        string capitalized = str;
        capitalized[0] = toupper(capitalized[0]);
        result.push_back(capitalized);
    }
    return result;
}

int main() {
    vector<string> vec = {"red", "green", "black", "white", "pink"};
    vector<string> capitalized = capitalizeFirstLetter(vec);
    
    cout << "Capitalized vector elements: ";
    for (const string& str : capitalized) {
        cout << str << " ";
    }
    return 0;
}
