#include <iostream> // Include the iostream library for input and output

int main() {
    int number; // Declare a variable to store the user's input

    // Prompt the user to enter a number
    std::cout << "Enter any Number: ";
    std::cin >> number; // Read the number from the user

    // Print the entered number
    std::cout << "Entered Number: " << number << std::endl;

    return 0; // Return 0 to indicate that the program ended successfully
}