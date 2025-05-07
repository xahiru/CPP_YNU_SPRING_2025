#include <iostream>
#include <vector>

int sumArray(const std::vector<int>& arr, int n) {
    if (n <= 0) return 0;
    return sumArray(arr, n - 1) + arr[n - 1];
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Array elements:\n";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nSum of array elements using recursion: " << sumArray(arr, arr.size()) << std::endl;

    return 0;
}
