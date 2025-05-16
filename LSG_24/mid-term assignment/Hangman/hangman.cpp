#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include <windows.h>

using namespace std;

// Function declarations (prototypes)
void initializeWords();
void initializeGame();
void drawHangman(int attempts);
void displayGame();
void getPlayerGuess();
bool isGameWon();
bool isGameOver();
void playGame();
void displayInstructions();
void displayScoreboard();

// Global variables
vector<string> words;
string secretWord;
string guessedWord;
int remainingAttempts = 6;
vector<char> guessedLetters;
int wins = 0, losses = 0;

int main() {
    srand(time(0));
    initializeWords();
    
    char choice;
    do {
        system("cls");
        cout << "=== HANGMAN GAME ===" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Instructions" << endl;
        cout << "3. View Scoreboard" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getch();
        
        switch(choice) {
            case '1': playGame(); break;
            case '2': displayInstructions(); break;
            case '3': displayScoreboard(); break;
            case '4': cout << "\nGoodbye!" << endl; break;
            default: cout << "\nInvalid choice! Try again." << endl;
        }
    } while(choice != '4');
    
    return 0;
}

void initializeWords() {
    words.push_back("programming");
    words.push_back("hangman");
    words.push_back("computer");
    words.push_back("keyboard");
    words.push_back("algorithm");
    words.push_back("developer");
    words.push_back("variable");
    words.push_back("function");
    words.push_back("console");
    words.push_back("windows");
}

void initializeGame() {
    secretWord = words[rand() % words.size()];
    guessedWord = string(secretWord.length(), '_');
    remainingAttempts = 6;
    guessedLetters.clear();
}

void drawHangman(int attempts) {
    cout << endl;
    switch(attempts) {
        case 6: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |" << endl;
                cout << " |" << endl;
                cout << " |" << endl;
                cout << "_|_" << endl;
                break;
        case 5: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |" << endl;
                cout << " |" << endl;
                cout << "_|_" << endl;
                break;
        case 4: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |     |" << endl;
                cout << " |" << endl;
                cout << "_|_" << endl;
                break;
        case 3: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |    /|" << endl;
                cout << " |" << endl;
                cout << "_|_" << endl;
                break;
        case 2: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |    /|\\" << endl;
                cout << " |" << endl;
                cout << "_|_" << endl;
                break;
        case 1: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |    /|\\" << endl;
                cout << " |    /" << endl;
                cout << "_|_" << endl;
                break;
        case 0: cout << "  _____" << endl;
                cout << " |     |" << endl;
                cout << " |     O" << endl;
                cout << " |    /|\\" << endl;
                cout << " |    / \\" << endl;
                cout << "_|_" << endl;
                break;
    }
    cout << endl;
}

void displayGame() {
    system("cls");
    cout << "=== HANGMAN ===" << endl;
    drawHangman(remainingAttempts);
    
    cout << "Word: ";
    for(size_t i = 0; i < guessedWord.length(); i++) {
        cout << guessedWord[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Guessed letters: ";
    for(size_t i = 0; i < guessedLetters.size(); i++) {
        cout << guessedLetters[i] << " ";
    }
    cout << endl;
    
    cout << "Attempts remaining: " << remainingAttempts << endl;
}

void getPlayerGuess() {
    char guess;
    cout << "\nEnter a letter: ";
    guess = getch();
    guess = tolower(guess);
    
    // Check if already guessed
    bool alreadyGuessed = false;
    for(size_t i = 0; i < guessedLetters.size(); i++) {
        if(guessedLetters[i] == guess) {
            alreadyGuessed = true;
            break;
        }
    }
    
    if(alreadyGuessed) {
        cout << "\nYou already guessed that letter!" << endl;
        Sleep(1000);
        return;
    }
    
    guessedLetters.push_back(guess);
    
    // Check if guess is correct
    bool correctGuess = false;
    for(size_t i = 0; i < secretWord.length(); i++) {
        if(secretWord[i] == guess) {
            guessedWord[i] = guess;
            correctGuess = true;
        }
    }
    
    if(!correctGuess) {
        remainingAttempts--;
        cout << "\nIncorrect guess!" << endl;
        Sleep(1000);
    }
}

bool isGameWon() {
    return guessedWord == secretWord;
}

bool isGameOver() {
    return remainingAttempts <= 0 || isGameWon();
}

void playGame() {
    initializeGame();
    
    while(!isGameOver()) {
        displayGame();
        getPlayerGuess();
    }
    
    displayGame();
    
    if(isGameWon()) {
        cout << "\nCongratulations! You won!" << endl;
        wins++;
    } else {
        cout << "\nGame over! The word was: " << secretWord << endl;
        losses++;
    }
    
    cout << "\nPress any key to continue...";
    getch();
}

void displayInstructions() {
    system("cls");
    cout << "=== HOW TO PLAY HANGMAN ===" << endl;
    cout << "1. Guess letters one at a time to reveal the hidden word" << endl;
    cout << "2. You have 6 incorrect guesses before losing" << endl;
    cout << "3. Each incorrect guess adds another part to the hangman" << endl;
    cout << "4. Win by guessing all letters in the word before the hangman is complete" << endl;
    cout << "\nPress any key to return to menu...";
    getch();
}

void displayScoreboard() {
    system("cls");
    cout << "=== SCOREBOARD ===" << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "\nPress any key to return to menu...";
    getch();
} 
