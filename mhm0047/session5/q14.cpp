#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1, 2, 3};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original Array: [";
    for (int i = 0; i < length; i++) {
        cout << numbers[i];
        if (i != length - 1) cout << ", ";
    }
    cout << "]" << endl;

    for (int &val : numbers) {
        val = val * 2;
    }

    cout << "Updated Array: [";
    for (int i = 0; i < length; i++) {
        cout << numbers[i];
        if (i != length - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}