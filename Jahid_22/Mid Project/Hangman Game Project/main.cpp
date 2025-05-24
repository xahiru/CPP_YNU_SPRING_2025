#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "hangman_functions.h"
using namespace std;

int main() {
    srand(time(0)); // Initialize random seed
    greet();

    char playAgain = 'y';
    while (tolower(playAgain) == 'y') {
        vector<string> wordBank = {
            "codingcleverly", "hangman", "developer", "cplusplus", "variable",
            "function", "looping", "terminal", "university", "keyboard",
            "internet", "computer", "debugger", "algorithm", "syntax",
            "compile", "project", "pointer", "execute", "hardware"
        };

        string codeword = wordBank[rand() % wordBank.size()];
        string answer(codeword.length(), '_');
        int misses = 0;
        vector<char> incorrect;
        bool guess = false;
        char letter;

        while (answer != codeword && misses < 7) {
            display_misses(misses);
            display_status(incorrect, answer);

            cout << "\n\nPlease enter your guess: ";
            cin >> letter;
            letter = tolower(letter);

            guess = false;

            for (int i = 0; i < codeword.length(); i++) {
                if (letter == codeword[i]) {
                    answer[i] = letter;
                    guess = true;
                }
            }

            if (guess) {
                cout << "\nCorrect!\n";
            } else {
                cout << "\nIncorrect! Another portion of the person has been drawn.\n";
                incorrect.push_back(letter);
                misses++;
            }
        }

        end_game(answer, codeword);

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";
    }

    cout << "Thank you for playing! Goodbye.\n";
    return 0;
}

