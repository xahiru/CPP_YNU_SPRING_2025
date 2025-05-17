#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Generic function to sort and print array
template <typename T>
void sortAndPrint(vector<T>& arr) {
    sort(arr.begin(), arr.end());
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int n, q;
    cin >> n >> q;

    if (q == 1) {
        // Integer case
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sortAndPrint(arr);
    }
    else if (q == 2) {
        // String case
        vector<string> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sortAndPrint(arr);
    }
    else if (q == 3) {
        // Floating-point case
        vector<float> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sortAndPrint(arr);
    }

    return 0;
}