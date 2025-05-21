#include <iostream> 
#include <vector> 
#include <string> 
#include <cctype> 

std::vector<std::string> capitalizeFirstLetter(std::vector<std::string> vec) { 
    for (std::string& s : vec) { 
        if (!s.empty()) { 
            s[0] = std::toupper(s[0]); 
        }
    }
    return vec; 
}

int main() {
    std::vector<std::string> originalVector = {"red", "green", "black", "white", "Pink"}; 
    std::cout << "Original Vector elements:"; 
    for (const std::string& s : originalVector) { 
        std::cout << " " << s; 
    }
    std::cout << std::endl; 

    std::vector<std::string> capitalizedVector = capitalizeFirstLetter(originalVector); 
    std::cout << "Capitalize the first character of each vector element:"; 
    for (const std::string& s : capitalizedVector) { 
        std::cout << " " << s; 
    std::cout << std::endl;

    return 0; 
}