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
        cout << (x < y ? x : y) << endl;
    }
};

int main() {
    int c;
    cin >> c;
    if (c == 1) {
        string str1, str2;
        cin >> str1 >> str2;
        MinElement<string> minStr(str1);
        minStr.check(str2);
    } else if (c == 2) {
        int int1, int2;
        cin >> int1 >> int2;
        MinElement<int> minInt(int1);
        minInt.check(int2);
    } else if (c == 3) {
        char char1, char2;
        cin >> char1 >> char2;
        MinElement<char> minChar(char1);
        minChar.check(char2);
    }
    return 0;
}
