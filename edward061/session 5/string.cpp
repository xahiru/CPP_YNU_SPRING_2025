cpp
#include <iostream>
#include <vector>
#include <cctype> 
using namespace std;

vector<string> capitalizeFirstLetter(vector<string>& vec) {
    for (string& str : vec) {
        if (!str.empty()) {
            str[0] = toupper(str[0]); 
        }
    }
    return vec;
}

int main() {

    vector<string> colors = {"red", "green", "black", "white", "pink"};

    cout << "Original Vector elements:" << endl;
    for (const string& color : colors) {
        cout << color << " ";
    }
    cout << endl;

    colors = capitalizeFirstLetter(colors);

    cout << "Capitalize the first character of each vector element:" << endl;
    for (const string& color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}