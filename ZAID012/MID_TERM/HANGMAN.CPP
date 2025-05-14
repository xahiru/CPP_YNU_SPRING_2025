#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void displayInstructions() {
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "1. Guess the word by suggesting letters one at a time." << std::endl;
    std::cout << "2. You have 6 incorrect guesses before losing." << std::endl;
    std::cout << "3. Each correct letter will be revealed in its position(s)." << std::endl;
    std::cout << "4. Try to guess the word before you run out of attempts!" << std::endl;
}

void displayScore(int score) {
    std::cout << "Current Score: " << score << std::endl;
}

std::string chooseRandomWord() {
    std::vector<std::string> words = {"hangman", "programming", "cplusplus", "development", "computer"};
    srand(time(0));
    return words[rand() % words.size()];
}

void playGame() {
    std::string word = chooseRandomWord();
    std::string guessed(word.length(), '_');
    int attempts = 6;
    std::vector<char> wrongGuesses;

    while (attempts > 0 && guessed != word) {
        std::cout << "\nWord: " << guessed << std::endl;
        displayScore(6 - attempts);
        std::cout << "Wrong guesses: ";
        for (char c : wrongGuesses) {
            std::cout << c << ' ';
        }
        std::cout << "\nEnter a letter: ";
        char guess;
        std::cin >> guess;

        bool correct = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            wrongGuesses.push_back(guess);
            --attempts;
            std::cout << "Incorrect! Attempts left: " << attempts << std::endl;
        }
    }

    if (guessed == word) {
        std::cout << "Congratulations! You've guessed the word: " << word << std::endl;
    } else {
        std::cout << "Game over! The word was: " << word << std::endl;
    }
}

int main() {
    displayInstructions();
    playGame();
    return 0;
}
