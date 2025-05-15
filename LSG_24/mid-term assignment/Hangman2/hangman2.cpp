#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <map>

using namespace std;

// Console colors
enum Color { RED=12, GREEN=10, YELLOW=14, BLUE=9, PURPLE=13, CYAN=11, WHITE=15 };

// Game states
enum GameMode { CLASSIC, TIME_ATTACK, SURVIVAL, DAILY_CHALLENGE };

// Player profile
struct PlayerProfile {
    string name;
    int level = 1;
    int xp = 0;
    int coins = 100;
    map<string, int> unlockedCategories;
    map<string, int> wordMastery;
    int streak = 0;
    time_t lastPlayed;
};

// Game session
struct GameSession {
    string secretWord;
    string guessedWord;
    int attemptsLeft;
    vector<char> guessedLetters;
    GameMode mode;
    time_t startTime;
    bool usedHint = false;
    bool usedPowerup = false;
};

// Global game objects
PlayerProfile player;
GameSession currentGame;
map<string, vector<string>> wordDatabase;
vector<vector<string>> asciiArtDatabase;

// ====== FUNCTION DECLARATIONS ======
void initGame();
void loadResources();
void loadProfile();
void saveProfile();
void shareResult();
void gainXP(int amount);
void rpgLevelUp();
void colorfulText(string text, Color color, bool animate=false);
void mainMenu();
void categorySelection();
void displayStats();
void dailyChallenge();
void startGame(GameMode mode);
void gameLoop();
void displayGame();
void processInput();
void checkGameState();
void drawHangman(int stage);

// ====== MAIN FUNCTION ======
int main() {
    initGame();
    
    while (true) {
        mainMenu();
        char choice = _getch();
        
        switch(toupper(choice)) {
            case '1': startGame(CLASSIC); break;
            case '2': categorySelection(); break;
            case '3': displayStats(); break;
            case '4': dailyChallenge(); break;
            case 'Q': return 0;
            default: 
                colorfulText("Invalid choice!", RED);
                Sleep(1000);
        }
    }
    return 0;
}

// ====== GAME INITIALIZATION ======
void initGame() {
    srand(time(0));
    loadResources();
    loadProfile();
    
    if (difftime(time(0), player.lastPlayed) > 86400) {
        dailyChallenge();
    }
}

void loadResources() {
    // Initialize word database
    wordDatabase["Technology"] = {"algorithm", "blockchain", "cybersecurity"};
    wordDatabase["Fantasy"] = {"dragon", "wizard", "enchanted"};
    
    // Initialize ASCII art - Complete hangman stages
    asciiArtDatabase = {
        // Stage 0 (no wrong guesses)
        {
            "  _____",
            " |     |",
            " |",
            " |",
            " |",
            "_|_"
        },
        // Stage 1 (head)
        {
            "  _____",
            " |     |",
            " |     O",
            " |",
            " |",
            "_|_"
        },
        // Stage 2 (head + body)
        {
            "  _____",
            " |     |",
            " |     O",
            " |     |",
            " |",
            "_|_"
        },
        // Stage 3 (head + body + one arm)
        {
            "  _____",
            " |     |",
            " |     O",
            " |    /|",
            " |",
            "_|_"
        },
        // Stage 4 (head + body + both arms)
        {
            "  _____",
            " |     |",
            " |     O",
            " |    /|\\",
            " |",
            "_|_"
        },
        // Stage 5 (head + body + arms + one leg)
        {
            "  _____",
            " |     |",
            " |     O",
            " |    /|\\",
            " |    /",
            "_|_"
        },
        // Stage 6 (complete hangman)
        {
            "  _____",
            " |     |",
            " |     O",
            " |    /|\\",
            " |    / \\",
            "_|_"
        }
    };
}

void loadProfile() {
    player.name = "Player";
    player.lastPlayed = time(0);
}

void saveProfile() {
    // Placeholder for saving functionality
}

// ====== GAME CORE FUNCTIONS ======
void startGame(GameMode mode) {
    currentGame.mode = mode;
    currentGame.attemptsLeft = (mode == SURVIVAL) ? 3 : 6;
    currentGame.guessedLetters.clear();
    
    // Select random category and word
    auto category = wordDatabase.begin();
    advance(category, rand() % wordDatabase.size());
    currentGame.secretWord = category->second[rand() % category->second.size()];
    
    // Initialize guessed word
    currentGame.guessedWord = string(currentGame.secretWord.length(), '_');
    currentGame.startTime = time(0);
    
    gameLoop();
}

void gameLoop() {
    while (true) {
        displayGame();
        processInput();
        checkGameState();
        
        if (currentGame.attemptsLeft <= 0 || 
            currentGame.guessedWord == currentGame.secretWord) {
            break;
        }
    }
    
    // Game over logic
    if (currentGame.guessedWord == currentGame.secretWord) {
        player.streak++;
        int score = currentGame.attemptsLeft * 100;
        gainXP(score / 10);
        colorfulText("VICTORY! Score: " + to_string(score), GREEN);
    } else {
        player.streak = 0;
        colorfulText("Game Over! Word was: " + currentGame.secretWord, RED);
    }
    
    saveProfile();
    shareResult();
    _getch(); // Wait for key press
}

// ====== UI FUNCTIONS ======
void colorfulText(string text, Color color, bool animate) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    if (animate) {
        for (char c : text) {
            cout << c << flush;
            Sleep(30);
        }
    } else {
        cout << text;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void mainMenu() {
    system("cls");
    colorfulText("=== HANGMAN PREMIUM ===", PURPLE, true);
    cout << "\n\n";
    
    colorfulText("1. Start New Game", CYAN);
    colorfulText("2. Select Category", CYAN);
    colorfulText("3. View Statistics", CYAN);
    colorfulText("4. Daily Challenge", CYAN);
    colorfulText("Q. Quit Game", RED);
    
    cout << "\n";
    colorfulText("Enter your choice: ", YELLOW);
}

void categorySelection() {
    system("cls");
    colorfulText("=== SELECT CATEGORY ===", BLUE, true);
    cout << "\n\n";
    
    int index = 1;
    for (auto const& category : wordDatabase) {
        colorfulText(to_string(index++) + ". " + category.first, GREEN);
    }
    
    cout << "\n";
    colorfulText("Enter category number: ", YELLOW);
    
    int choice;
    cin >> choice;
    // Add validation logic here
}

void displayStats() {
    system("cls");
    colorfulText("=== PLAYER STATISTICS ===", CYAN, true);
    cout << "\n\n";
    
    cout << "Level: " << player.level << endl;
    cout << "XP: " << player.xp << "/" << (player.level * 100) << endl;
    colorfulText("Coins: " + to_string(player.coins), YELLOW);
    colorfulText("Current Streak: " + to_string(player.streak), GREEN);
    
    cout << "\n";
    colorfulText("Press any key to continue...", BLUE);
    _getch();
}

// ====== GAME MECHANICS ======
void displayGame() {
    system("cls");
    colorfulText("=== HANGMAN ===", PURPLE);
    
    // Calculate current stage (6 - attemptsLeft gives 0-6 range)
    int currentStage = 6 - currentGame.attemptsLeft;
    drawHangman(currentStage);
    
    cout << "\nWord: ";
    for (size_t i = 0; i < currentGame.guessedWord.length(); i++) {
        if (currentGame.guessedWord[i] == '_') {
            colorfulText("_ ", RED);
        } else {
            colorfulText(string(1, currentGame.guessedWord[i]) + " ", GREEN);
        }
    }
    
    cout << "\n\nGuessed letters: ";
    for (size_t i = 0; i < currentGame.guessedLetters.size(); i++) {
        cout << currentGame.guessedLetters[i] << " ";
    }
    
    cout << "\nAttempts left: " << currentGame.attemptsLeft << endl;
}

void processInput() {
    char guess = _getch();
    guess = tolower(guess);
    
    // Check if already guessed
    for (size_t i = 0; i < currentGame.guessedLetters.size(); i++) {
        if (currentGame.guessedLetters[i] == guess) {
            colorfulText("\nAlready guessed!", YELLOW);
            Sleep(1000);
            return;
        }
    }
    
    currentGame.guessedLetters.push_back(guess);
    
    // Check if guess is correct
    bool correct = false;
    for (size_t i = 0; i < currentGame.secretWord.length(); i++) {
        if (currentGame.secretWord[i] == guess) {
            currentGame.guessedWord[i] = guess;
            correct = true;
        }
    }
    
    if (!correct) {
        currentGame.attemptsLeft--;
    }
}

void checkGameState() {
    if (currentGame.guessedWord == currentGame.secretWord) {
        colorfulText("\nYou won!", GREEN);
    } else if (currentGame.attemptsLeft <= 0) {
        colorfulText("\nGame over! The word was: " + currentGame.secretWord, RED);
    }
}

// ====== HANGMAN DRAWING FUNCTIONS ======
void drawHangman(int stage) {
    // Ensure stage is within bounds
    if (stage < 0) stage = 0;
    if (stage >= (int)asciiArtDatabase.size()) stage = asciiArtDatabase.size() - 1;
    
    // Draw each line of the hangman for this stage
    for (size_t i = 0; i < asciiArtDatabase[stage].size(); i++) {
        colorfulText(asciiArtDatabase[stage][i], RED);
    }
}

// ====== SPECIAL GAME MODES ======
void dailyChallenge() {
    system("cls");
    colorfulText("=== DAILY CHALLENGE ===", PURPLE, true);
    colorfulText("\nToday's special challenge word!", GREEN);
    
    currentGame.secretWord = "achievement";
    currentGame.guessedWord = string(currentGame.secretWord.length(), '_');
    currentGame.attemptsLeft = 6;
    currentGame.guessedLetters.clear();
    
    gameLoop();
}

// ====== RPG PROGRESSION ======
void gainXP(int amount) {
    player.xp += amount;
    if (player.xp >= player.level * 100) {
        rpgLevelUp();
    }
}

void rpgLevelUp() {
    player.level++;
    player.xp = 0;
    player.coins += 50;
    colorfulText("\nLEVEL UP! You are now level " + to_string(player.level), PURPLE);
    Sleep(2000);
}

void shareResult() {
    // Placeholder for sharing functionality
}
