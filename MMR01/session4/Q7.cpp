#include <iostream>
#include <string>
#include <iomanip> // For std::setprecision

int main() {
    int rows, cols;
    
    // Get array dimensions from user
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    
    // Dynamically allocate 2D array of floats
    float** floatArray = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        floatArray[i] = new float[cols];
    }
    
    // Initialize float array with sample values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            floatArray[i][j] = (i + 1) * 1.5f + (j * 0.1f); // Example pattern
        }
    }
    
    // Dynamically allocate 2D array of strings
    std::string** stringArray = new std::string*[rows];
    for (int i = 0; i < rows; ++i) {
        stringArray[i] = new std::string[cols];
    }
    
    // Initialize string array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            stringArray[i][j] = "Row " + std::to_string(i + 1) + 
                               ", Col " + std::to_string(j + 1);
        }
    }
    
    // Display the float array
    std::cout << "\nFloat Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::fixed << std::setprecision(2) 
                      << floatArray[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    // Display the string array
    std::cout << "\nString Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << stringArray[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] floatArray[i];
        delete[] stringArray[i];
    }
    delete[] floatArray;
    delete[] stringArray;
    
    return 0;
}