#include <iostream>
using namespace std;

int main() {
    char c1, c2;
    cin >> c1 >> c2;
    for (char current = c1; current <= c2; ++current) {
        cout << current << ' ';
    }
    return 0;
}