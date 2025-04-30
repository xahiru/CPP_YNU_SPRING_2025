#include <iostream>
#include <cstring>
using namespace std;

bool containsNumber(const char* str) {
    while (*str) {
        if (isdigit(*str)) return true;
        str++;
    }
    return false;
}

void filterStringsWithNumbers(char arr[][20], int size) {
    cout << "Find strings that contain a number(s) from the said vector:\n";
    for (int i = 0; i < size; ++i) {
        if (containsNumber(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    char arr[4][20] = {"red", "green23", "1black", "white"};
    cout << "Original Vector elements:\n";
    for (int i = 0; i < 4; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    filterStringsWithNumbers(arr, 4);
    return 0;
}