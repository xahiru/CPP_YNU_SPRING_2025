#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int countOne = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            countOne++;
        }
    }
    for (int i = 0; i < n - countOne; i++) {
        arr[i] = 0;
    }
    for (int i = n - countOne; i < n; i++) {
        arr[i] = 1;
    }
    cout << "Array after divided: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
