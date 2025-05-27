#include <iostream>

using namespace std;

int main() {
    char c1, c2;
    cin >> c1 >> c2;

    for (char c = c1; c <= c2; ++c) {
        cout << c << " ";
    }
    
    return 0;
}