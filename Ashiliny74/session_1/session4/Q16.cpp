#include <iostream>
#include <string>
#include <algorithm> // For std::transform
using namespace std;

int main() {
    // Define the strings
    string str1 = "Geeks";
    string str2 = "geeks";

    // Compare the strings
    if (str1 == str2) {
        cout << "str1 and str2 are equal." << endl;
    } else {
        cout << "str1 and str2 are not equal." << endl;
    }

    // Optional: Case-insensitive comparison
    string str1_lower = str1;
    string str2_lower = str2;

    // Convert both strings to lowercase
    transform(str1_lower.begin(), str1_lower.end(), str1_lower.begin(), ::tolower);
    transform(str2_lower.begin(), str2_lower.end(), str2_lower.begin(), ::tolower);

    // Compare the lowercase strings
    if (str1_lower == str2_lower) {
        cout << "str1 and str2 are equal (case-insensitive)." << endl;
    } else {
        cout << "str1 and str2 are not equal (case-insensitive)." << endl;
    }

    return 0;
}