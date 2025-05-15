#include <iostream>
#include <string>

int main() {
    int size;
    

    std::cout << "Enter the size of the arrays: ";
    std::cin >> size;
    
    // Dynamically allocate array of integers
    int* intArray = new int[size];
    
    // Initialize integer array
    for (int i = 0; i < size; ++i) {
        intArray[i] = i * 10;  // Example initialization
    }
    
    // Dynamically allocate array of strings
    std::string* stringArray = new std::string[size];
    
    // Initialize string array
    for (int i = 0; i < size; ++i) {
        stringArray[i] = "String " + std::to_string(i + 1); 
    }
    
    // Display the integer array
    std::cout << "\nInteger Array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << intArray[i] << " ";
    }
    
    // Display the string array
    std::cout << "\n\nString Array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << stringArray[i] << "\n";
    }
    
    // Deallocate memory to prevent memory leaks
    delete[] intArray;
    delete[] stringArray;
    
    return 0;
}