#include <iostream> // Include the iostream library for input and output

int main() {
    char character; // Declare a variable to store the character input

    // Prompt the user to enter a character
    std::cout << "Enter a character: ";
    std::cin >> character; // Read the character from the user

    // Print the ASCII value of the entered character
    std::cout << "ASCII Value of '" << character << "' = " << static_cast<int>(character) << std::endl;

    return 0; // Return 0 to indicate that the program ended successfully
}