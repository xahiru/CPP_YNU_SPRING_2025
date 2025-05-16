#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = 0; j <= i; ++j) {
            s += 'A' + j;
            s += ' ';
        }
        for (int j = i-1; j >= 0; --j) {
            s += 'A' + j;
            s += ' ';
        }
        if (!s.empty()) s.pop_back();
        cout << s << endl;
    }
    return 0;
}