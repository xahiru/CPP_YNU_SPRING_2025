#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MinElement {
private:
    T y;
public:
    MinElement(T val) : y(val) {}
    void check(T x) {
        cout << (x < y ? x : y);
    }
};

int main() {
    int c;
    cin >> c;
    if (c == 1) {
        string a, b;
        cin >> a >> b;
        MinElement<string> m(a);
        m.check(b);
    } else if (c == 2) {
        int a, b;
        cin >> a >> b;
        MinElement<int> m(a);
        m.check(b);
    } else if (c == 3) {
        char a, b;
        cin >> a >> b;
        MinElement<char> m(a);
        m.check(b);
    }
    return 0;
}