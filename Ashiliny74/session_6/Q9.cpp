#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    for (char c = c1; c <= c2; c++) {
        cout << c << " ";
    }
}

int main() {
    char c1, c2;
    cin >> c1 >> c2;
    printAlphabets(c1, c2);
    return 0;
}