#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <cctype>
#include <limits> 

using namespace std;

// ANSI Color Codes for terminal output
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string CYAN = "\033[1;36m";
const string RESET = "\033[0m";

// FUNCTION DECLARATIONS
void clearScreen();
void printInstructions();
void loadScore(int &wins, int &losses);
void saveScore(int wins, int losses);
string chooseRandomWord(const string &filename, string Level);
string revealLetters(const string &word);
char getLetterInput(const string &prompt);
string getLevelInput();
void playGame(int &wins, int &losses, string Level);

// UTILITY FUNCTIONS

void clearScreen() {
    system("clear"); // For Linux systems
    // system("cls"); For Windows systems
}

void printInstructions() {
    cout << CYAN << "====== HANGMAN GAME ======" << RESET << endl;
    cout << "Guess the hidden word letter by letter.\n";
    cout << "You have 6 incorrect attempts.\n";
    cout << "Some letters are revealed to help you start!\n";
    cout << "Select Level to change word length.\n" << endl;
}

// SCORE MANAGEMENT

void loadScore(int &wins, int &losses) {
    ifstream file("score.txt");
    if (file >> wins >> losses) {
        file.close();
    } else {
        wins = 0;
        losses = 0;
    }
}

void saveScore(int wins, int losses) {
    ofstream file("score.txt");
    if (file.is_open()) {
        file << wins << " " << losses;
        file.close();
    }
}

// INPUT VALIDATION FUNCTIONS

char getLetterInput(const string &prompt) {
    char input;
    while (true) {
        cout << prompt;
        cin >> input;
        
        if (cin.fail() || !isalpha(input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input! Please enter a letter (a-z)." << RESET << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return tolower(input);
        }
    }
}

string getLevelInput() {
    string input;
    while (true) {
        cout << "Select Level:\n1. Easy\n2. Medium\n3. Hard\n> ";
        cin >> input;
        
        if (input == "1" || input == "2" || input == "3") {
            return input;
        } else {
            cout << RED << "Invalid choice! Please enter 1, 2, or 3." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// GAME LOGIC

string chooseRandomWord(const string &filename, string Level) {
    vector<string> words;
    ifstream file(filename);
    string word;

    if (!file.is_open()) {
        cerr << "Error: Could not open words file. Using default word." << endl;
        return "hangman";
    }

    while (file >> word) {
        if (Level == "1" && word.length() <= 5) {
            words.push_back(word);
        } else if (Level == "2" && word.length() > 5 && word.length() <= 8) {
            words.push_back(word);
        } else if (Level == "3" && word.length() > 8) {
            words.push_back(word);
        }
    }
    file.close();

    if (words.empty()) {
        return "hangman";
    }

    srand(time(0));
    return words[rand() % words.size()];
}

string revealLetters(const string &word) {
    string revealed(word.length(), '_');
    set<int> revealedIndices;
    
    // Determine how many letters to reveal (1 for short words, 2 for longer)
    int lettersToReveal = word.length() <= 4 ? 1 : 2;
    
    // Select random distinct positions to reveal
    while (revealedIndices.size() < lettersToReveal) {
        int pos = rand() % word.length();
        revealedIndices.insert(pos);
    }
    
    // Reveal the selected letters
    for (int pos : revealedIndices) {
        revealed[pos] = word[pos];
    }
    
    return revealed;
}

void playGame(int &wins, int &losses, string Level) {
    string word = chooseRandomWord("words.txt", Level);
    string guessed = revealLetters(word);
    int maxTries = 6;
    vector<char> usedLetters;

    // Add the initially revealed letters to usedLetters
    for (char c : guessed) {
        if (c != '_') {
            usedLetters.push_back(tolower(c));
        }
    }

    while (maxTries > 0 && guessed != word) {
        cout << YELLOW << "Word: " << guessed << RESET << endl;
        cout << "Attempts left: " << RED << maxTries << RESET << endl;
        cout << "Used letters: ";
        for (char c : usedLetters) {
            cout << c << " ";
        }
        cout << endl;

        char guess = getLetterInput("Enter a letter: ");

        if (find(usedLetters.begin(), usedLetters.end(), guess) != usedLetters.end()) {
            cout << RED << "You already guessed that letter!" << RESET << endl;
            continue;
        }

        usedLetters.push_back(guess);
        bool correct = false;

        for (size_t i = 0; i < word.length(); ++i) {
            if (tolower(word[i]) == guess) {
                guessed[i] = word[i];
                correct = true;
            }
        }

        if (!correct) {
            maxTries--;
            cout << RED << "Incorrect guess!" << RESET << endl;
        }

        clearScreen();
    }

    if (guessed == word) {
        cout << GREEN << "You guessed it! The word was: " << word << RESET << endl;
        wins++;
    } else {
        cout << RED << "You lost! The word was: " << word << RESET << endl;
        losses++;
    }

    cout << CYAN << "Scoreboard: Wins = " << wins << ", Losses = " << losses << RESET << endl << endl;
    saveScore(wins, losses);
}

int main() {
    int wins = 0, losses = 0;
    char choice;
    
    // Seed random number generator
    srand(time(0));

    loadScore(wins, losses);
    printInstructions();

    string Level = getLevelInput();
    clearScreen();

    do {
        playGame(wins, losses, Level);
        choice = getLetterInput("Play again? (y/n): ");
        clearScreen();
    } while (tolower(choice) == 'y');

    cout << GREEN << "Thanks for playing!" << RESET << endl;
    return 0;
}