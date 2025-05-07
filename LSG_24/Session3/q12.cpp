#include <iostream>
#include <algorithm>
using namespace std;

void permute(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            permute(str, left + 1, right);
            swap(str[left], str[i]); // backtrack
        }
    }
}

int main() {
    string str;
    cout << "Input a string: ";
    cin >> str;
    cout << "All permutations of the string:\n";
    permute(str, 0, str.length() - 1);
    return 0;
}