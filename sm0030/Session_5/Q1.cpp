#include <iostream> 
#include <vector> 
#include <algorithm> 

std::vector<int> findSmallerThanNeighbors(const std::vector<int>& arr) { 
    std::vector<int> result; 
    if (arr.size() < 3) { 
        return result; 
    }
    for (size_t i = 1; i < arr.size() - 1; ++i) { 
        if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) { 
            result.push_back(arr[i]); 
        }
    }
    return result; 
}

int main() {
    std::vector<int> originalVector = {1, 2, 5, 0, 3, 1, 7}; 
    std::cout << "Original Vector elements:"; 
    for (int x : originalVector) { 
        std::cout << " " << x;
    }
    std::cout << std::endl; 
    std::vector<int> smallerElements = findSmallerThanNeighbors(originalVector); 
    std::cout << "Vector elements that are smaller than its adjacent neighbours:";
    for (int x : smallerElements) { 
        std::cout << " " << x; 
    }
    std::cout << std::endl; 

    return 0; 
}