#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr = {7, 12, 9, 15, 19, 32, 56, 70};
    std::sort(arr.rbegin(), arr.rend());

    std::cout << "Three largest elements are: " << arr[0] << ", " << arr[1] << ", " << arr[2] << std::endl;
    return 0;
}
