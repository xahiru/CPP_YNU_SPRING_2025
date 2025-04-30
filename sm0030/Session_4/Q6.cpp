#include <iostream>
#include <string>

int main() {
 
    int intSize = 5;
    int* intArray = new int[intSize];
    for (int i = 0; i < intSize; ++i) {
        intArray[i] = i * 2;
    }
    std::cout << "Integer array: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] intArray; 

  
    int strSize = 3;
    std::string* strArray = new std::string[strSize];
    for (int i = 0; i < strSize; ++i) {
        strArray[i] = "String " + std::to_string(i + 1); 
    }
    std::cout << "String array: ";
    for (int i = 0; i < strSize; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] strArray; 

    return 0;
}