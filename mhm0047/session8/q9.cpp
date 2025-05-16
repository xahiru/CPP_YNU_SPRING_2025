#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q = 3;

    if (q == 1) {
        int arr[] = {123, -2311, 837, 0};
        sort(arr, arr + 4);
        for (int i = 0; i < 4; i++) cout << arr[i] << " ";
    } else if (q == 2) {
        string arr[] = {"banana", "apple", "zebra"};
        sort(arr, arr + 3);
        for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    } else {
        float arr[] = {34.23, -4.35, 3.4};
        sort(arr, arr + 3);
        for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    }

    return 0;
}
