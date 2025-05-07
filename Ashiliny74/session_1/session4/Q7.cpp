#include <iostream>
#include <string>

int main() {
    // Dimensions for the 2D arrays
    int rows, cols;

    // Input for dimensions
    std::cout << "Enter the number of rows and columns for the arrays: ";
    std::cin >> rows >> cols;

    // Dynamically allocate a 2D array for floating-point values
    float** floatArray = new float*[rows]; // Allocate array of pointers
    for (int i = 0; i < rows; i++) {
        floatArray[i] = new float[cols]; // Allocate each row
    }

    // Initialize the floating-point array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            floatArray[i][j] = (i + 1) * (j + 1) * 1.1; // Example initialization
        }
    }

    // Dynamically allocate a 2D array for strings
    std::string** strArray = new std::string*[rows]; // Allocate array of pointers
    for (int i = 0; i < rows; i++) {
        strArray[i] = new std::string[cols]; // Allocate each row
    }

    // Initialize the string array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            strArray[i][j] = "Element " + std::to_string(i + 1) + "," + std::to_string(j + 1); // Example initialization
        }
    }

    // Output the floating-point array
    std::cout << "\nFloating-point array elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << floatArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Output the string array
    std::cout << "\nString array elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << strArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate the memory for the floating-point array
    for (int i = 0; i < rows; i++) {
        delete[] floatArray[i]; // Free each row
    }
    delete[] floatArray; // Free the array of pointers

    // Deallocate the memory for the string array
    for (int i = 0; i < rows; i++) {
        delete[] strArray[i]; // Free each row
    }
    delete[] strArray; // Free the array of pointers

    return 0;
}