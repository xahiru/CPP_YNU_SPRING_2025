#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

// Game configuration
const vector<string> WORDS = {
    "apple", "banana", "orange", "grapes", "mango",
    "python", "java", "javascript", "ruby",
    "elephant", "giraffe", "kangaroo", "dolphin"
};

const int MAX_ATTEMPTS = 5;
const int COUNTDOWN_SECONDS = 3;

void clearScreen() {
    cout << string(50, '\n');  // Cross-platform screen clear alternative
}

string selectRandomWord() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
    return WORDS[rand() % WORDS.size()];
}

string scrambleWord(const string& word) {
    string scrambled = word;
    random_device rd;
    mt19937 g(rd());
    shuffle(scrambled.begin(), scrambled.end(), g);
    return scrambled;
}

void displayCountdown() {
    for (int i = COUNTDOWN_SECONDS; i > 0; --i) {
        cout << "Game starting in " << i << "...\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    clearScreen();
}

void playGame() {
    string original = selectRandomWord();
    string scrambled = scrambleWord(original);
    int attempts = 0;

    cout << "=== WORD PUZZLE GAME ===\n\n";
    cout << "Unscramble the word: " << scrambled << "\n\n";

    while (attempts < MAX_ATTEMPTS) {
        string guess;
        cout << "Enter your guess (" << MAX_ATTEMPTS - attempts << " attempts left): ";
        cin >> guess;

        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess == original) {
            cout << "\nCorrect! You guessed it!\n";
            return;
        } else {
            cout << "Incorrect. Try again.\n";
            attempts++;
        }
    }

    cout << "\nGame over! The word was: " << original << "\n";
}

int main() {
    clearScreen();
    displayCountdown();
    
    char playAgain;
    do {
        playGame();
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
    } while (tolower(playAgain) == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}