#include <iostream>
#include <string>
using namespace std;

int firstOccurrence(const string& txt, const string& pat) {
    size_t index = txt.find(pat);
    return (index != string::npos) ? index : -1;
}

int main() {
    string txt = "YunnanUniversity";
    string pat = "nan";
    cout << firstOccurrence(txt, pat) << endl; // Output: 3
    return 0;
}
