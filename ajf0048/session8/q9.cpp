#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
T findLargest(const std::vector<T>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

int main() {
    int n, K;
    std::cin >> n >> K;

    if (K == 1) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        std::cout << findLargest(arr) << std::endl;
    } else if (K == 2) {
        std::vector<float> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        std::cout << std::fixed << std::setprecision(2) << findLargest(arr) << std::endl;
    }

    return 0;
}