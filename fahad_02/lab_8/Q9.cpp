#include <iostream>
#include <vector>
using namespace std;

// Function template to find maximum element in an array
template <typename T>
T findMax(const vector<T>& arr) {
    T maxVal = arr[0];
    for (const auto& element : arr) {
        if (element > maxVal) {
            maxVal = element;
        }
    }
    return maxVal;
}

int main() {
    int n, K;
    cin >> n >> K;

    if (K == 1) {
        // Integer case
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << findMax(arr) << endl;
    } 
    else if (K == 2) {
        // Float case
        vector<float> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << findMax(arr) << endl;
    }

    return 0;
}