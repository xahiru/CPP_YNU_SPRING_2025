#include <iostream>
using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]); 
        }
    }
}

int main() {
    string s;
    cout << "Input a string: ";
    cin >> s;

    cout << "All permutations of the string:" << endl;
    permute(s, 0, s.length() - 1);

    return 0;
}