#include <iostream>
#include <vector>

void sort012(std::vector<int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                std::swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    std::vector<int> arr = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    sort012(arr);

    std::cout << "Array elements after rearranging: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
