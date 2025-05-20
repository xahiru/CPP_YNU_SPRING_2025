#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    for (char ch = c1; ch <= c2; ++ch) {
        cout << ch << " ";
    }
}

int main() {
    char c1 = 'a';
    char c2 = 'z';
    printAlphabets(c1, c2);
    return 0;
}
