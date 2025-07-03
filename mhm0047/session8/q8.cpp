#include <iostream>
using namespace std;

int main() {
    int K = 1, n = 5;

    if (K == 1) {
        int arr[] = {1, 8, 7, 56, 90}, maxVal = arr[0];
        for (int i = 1; i < n; ++i)
            if (arr[i] > maxVal) maxVal = arr[i];
        cout << maxVal;
    } else {
        float arr[] = {1.1, 2.2, 0, 3.2, 5.0}, maxVal = arr[0];
        for (int i = 1; i < n; ++i)
            if (arr[i] > maxVal) maxVal = arr[i];
        cout << maxVal;
    }

    return 0;
}
