#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayInstructions() {
    cout << "=== Hangman Game Instructions ===" << endl;
    cout << "Guess the hidden word one letter at a time." << endl;
    cout << "You have a limited number of incorrect guesses." << endl;
    cout << "Incorrect guesses will reduce your attempts left." << endl;
    cout << "Good luck!\n" << endl;
}

void displayGameState(const string& word, const vector<bool>& guessed, int attemptsLeft, const string& wrongGuesses) {
    cout << "Word: ";
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << "\nAttempts Left: " << attemptsLeft;
    cout << "\nWrong Guesses: " << wrongGuesses << "\n" << endl;
}

bool playHangman(const string& word) {
    int maxAttempts = 6;
    int attemptsLeft = maxAttempts;
    vector<bool> guessed(word.length(), false);
    string wrongGuesses;

    while (attemptsLeft > 0) {
        displayGameState(word, guessed, attemptsLeft, wrongGuesses);
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (tolower(word[i]) == guess && !guessed[i]) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            if (wrongGuesses.find(guess) == string::npos) {
                wrongGuesses += guess;
                wrongGuesses += ' ';
                --attemptsLeft;
            }
        }

        if (all_of(guessed.begin(), guessed.end(), [](bool b) { return b; })) {
            displayGameState(word, guessed, attemptsLeft, wrongGuesses);
            cout << "🎉 Congratulations! You guessed the word!\n" << endl;
            return true;
        }
    }

    displayGameState(word, guessed, 0, wrongGuesses);
    cout << "💀 Game Over! The word was: " << word << "\n" << endl;
    return false;
}

int main() {
    vector<string> words = {"computer", "hangman", "hacker", "university", "security"};
    srand(time(0));
    string word = words[rand() % words.size()];

    clearScreen();
    displayInstructions();
    playHangman(word);

    return 0;
}
