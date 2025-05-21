#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void sortArray(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    int n, q;
    std::cin >> n >> q;

    if (q == 1) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        sortArray(arr);
        for (int val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } else if (q == 2) {
        std::vector<float> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        sortArray(arr);
        for (float val : arr) {
            std::cout << std::fixed << std::setprecision(2) << val << " ";
        }
        std::cout << std::endl;
    } else if (q == 3) {
        std::vector<std::string> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        sortArray(arr);
        for (const std::string& val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}