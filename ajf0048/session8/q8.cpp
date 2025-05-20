#include <iostream>
#include <string>

template <typename T>
class minElement {
private:
    T y;

public:
    minElement(T val) : y(val) {}

    void check(T x) {
        std::cout << (x < y ? x : y) << std::endl;
    }
};

int main() {
    int c;
    std::cin >> c;

    if (c == 1) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        minElement<std::string> obj(s1);
        obj.check(s2);
    } else if (c == 2) {
        int i1, i2;
        std::cin >> i1 >> i2;
        minElement<int> obj(i1);
        obj.check(i2);
    } else if (c == 3) {
        char c1, c2;
        std::cin >> c1 >> c2;
        minElement<char> obj(c1);
        obj.check(c2);
    }

    return 0;
}