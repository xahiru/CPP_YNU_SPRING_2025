#include <iostream>
using namespace std;

template<typename T>
class minElement {
    T y;
public:
    minElement(T val) : y(val) {}
    void check(T x) { cout << (x < y ? x : y) << endl; }
};

int main() {
    int c; cin >> c;
    if (c == 1) { string a, b; cin >> a >> b; minElement<string>(a).check(b); }
    else if (c == 2) { int a, b; cin >> a >> b; minElement<int>(a).check(b); }
    else if (c == 3) { char a, b; cin >> a >> b; minElement<char>(a).check(b); }
}