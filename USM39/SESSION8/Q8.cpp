#include <iostream>
#include <string>
using namespace std;

template <typename T>
class minElement {
private:
    T y;
public:
    minElement(T val) : y(val) {}
    void check(T x) {
        cout << (x < y ? x : y) << endl;
    }
};

int main() {
    int c;
    cin >> c;
    if (c == 1) {
        string s1, s2;
        cin >> s1 >> s2;
        minElement<string> me(s1);
        me.check(s2);
    } else if (c == 2) {
        int i1, i2;
        cin >> i1 >> i2;
        minElement<int> me(i1);
        me.check(i2);
    } else if (c == 3) {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        minElement<char> me(ch1);
        me.check(ch2);
    }
    return 0;
}
