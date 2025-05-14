#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayInstructions() {
    cout << "**********************************************************************" << endl;
    cout << "*                    Number Guessing Game                            *" << endl;
    cout << "*                                                                    *" << endl;
    cout << "*  Instructions:                                                     *" << endl;
    cout << "*  1. The system will generate a random number between 1 and 100.    *" << endl;
    cout << "*  2. Your task is to guess the number.                              *" << endl;
    cout << "*  3. The system will tell you if your guess is too high or too low. *" << endl;
    cout << "*  4. The current guessing range will be displayed after each guess. *" << endl;
    cout << "*  5. You get 1 point for each correct guess.                        *" << endl;
    cout << "*  6. After each game, a statistics window will appear.              *" << endl;
    cout << "*                                                                    *" << endl;
    cout << "**********************************************************************" << endl << endl;
}

int generateRandomNumber() {
    return rand() % 100 + 1; // Returns a random number between 1 and 100
}

void showStatistics(int totalGames, int totalScore, int lastGameAttempts) {
    cout << "\n";
    cout << "**********************************************************************" << endl;
    cout << "                          Game Statistics                            " << endl;
    cout << "**********************************************************************" << endl;
    cout << "Total games played: " << totalGames << endl;
    cout << "Total score: " << totalScore << endl;
    cout << "Last game attempts: " << lastGameAttempts << endl; // Display last game attempts
    cout << "**********************************************************************" << endl;
    cout << "Press Enter to continue...";
    cin.get(); // Wait for Enter key
    cout << "\n";
}

void playGame(int &totalGames, int &totalScore) {
    int randomNumber = generateRandomNumber();
    int guess;
    int minRange = 1;
    int maxRange = 100;
    int attempts = 0; // Track the number of attempts in the current game

    cout << "A new game has started!" << endl;
    cout << "I've thought of a number between 1 and 100." << endl;

    while (true) {
        cout << "Current range: " << minRange << " - " << maxRange << endl;
        cout << "Enter your guess: ";

        // Simple input validation using a flag
        bool validInput = false;
        while (!validInput) {
            if (cin >> guess) {
                validInput = true;
                // Check if the guess is within the valid range
                if (guess < minRange || guess > maxRange) {
                    cout << "Please enter a number within the current range!" << endl;
                    validInput = false;
                }
            } else {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear(); // Clear the error flag
                cin.ignore(10000, '\n'); // Ignore the incorrect input
            }
        }

        attempts++; // Increment the attempt counter

        // Provide feedback based on the user's guess
        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
            minRange = guess + 1;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
            maxRange = guess - 1;
        } else {
            totalScore++;
            cout << "Congratulations! You've guessed it right! The correct number is " << randomNumber << "." << endl;
            cout << "You made " << attempts << " attempts in this game." << endl;
            break;
        }
    }
    totalGames++;
    showStatistics(totalGames, totalScore, attempts); // Pass the attempts to showStatistics
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    displayInstructions();

    int totalGames = 0;
    int totalScore = 0;

    char playAgain;
    do {
        playGame(totalGames, totalScore);
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(10000, '\n'); // Clear the input buffer
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing the Number Guessing Game! Goodbye!" << endl;
    return 0;
}