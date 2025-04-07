#include <iostream>
#include <string>
using namespace std;

string numberToWord(int n) {
    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight"};
    if (n >= 0 && n <= 8) {
        return words[n];
    } else {
        return "Greater than 9";
    }
}

int main() {
    int n;
    cin >> n;
    cout << numberToWord(n) << endl;
    return 0;
}