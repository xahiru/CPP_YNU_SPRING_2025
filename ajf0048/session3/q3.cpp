#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    cout << "Second smallest number: " << second << endl;
    return 0;
}
