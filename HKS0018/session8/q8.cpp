#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class minElement {
private:
    T y;

public:
    minElement(T value) : y(value) {}
    void check(T x) {
        if (x < y) {
            cout << x << endl;
        } else {
            cout << y << endl;
        }
    }

};

int main() {
    int c;
    cin >> c;
    
    if (c == 1) {
        string a, b;
        cin >> a >> b;
        minElement<string> obj(b);
        obj.check(a);
    } else if (c == 2) {
        int a, b;
        cin >> a >> b;
        minElement<int> obj(b);
        obj.check(a);
    } else if (c == 3) {
        char a, b;
        cin >> a >> b;
        minElement<char> obj(b);
        obj.check(a);
    }
    
    return 0;

}