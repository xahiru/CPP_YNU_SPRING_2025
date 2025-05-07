#include <iostream>
#include <string>
using namespace std;


void swap(string &str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void generatePermutations(string &str, int l, int r) {

    if (l == r) {
        cout << str << endl;
    } else {

        for (int i = l; i <= r; i++) {

            swap(str, l, i);

            generatePermutations(str, l + 1, r);

            swap(str, l, i);
        }
    }
}

int main() {
    string str;

    cout << "Input a string: ";
    cin >> str;

    cout << "All permutations of the string:" << endl;
    generatePermutations(str, 0, str.length() - 1);

    return 0;
}