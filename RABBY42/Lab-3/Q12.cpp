#include <iostream>
#include <algorithm>
using namespace std;

void permute(string s, int left, int right) {
    if (left == right) {
        cout << s << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(s[left], s[i]);
            permute(s, left + 1, right);
            swap(s[left], s[i]); // backtrack
        }
    }
}

int main() {
    string s;
    cout << "Input a string: ";
    cin >> s;
    cout << "All permutations:" << endl;
    permute(s, 0, s.size() - 1);
    return 0;
}