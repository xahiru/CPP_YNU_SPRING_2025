#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <iomanip>

// ANSI color codes for console output
namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string BLACK   = "\033[30m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string WHITE   = "\033[37m";
    const std::string BOLD    = "\033[1m";
}

// Cross-platform console clearing
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Difficulty levels
enum class Difficulty {
    EASY,   // Common words (4-6 letters)
    MEDIUM, // Moderate words (7-9 letters)
    HARD    // Challenging words (10+ letters)
};

// Word categories
enum class Category {
    ANIMALS,
    COUNTRIES,
    FOOD,
    SPORTS,
    MOVIES,
    RANDOM
};

// Game class
class HangmanGame {
private:
    // Game state
    std::string word;
    std::vector<char> guessedLetters;
    int attemptsLeft;
    Difficulty difficulty;
    Category category;
    bool gameOver;
    bool gameWon;
    bool colorEnabled;
    
    // Word database
    std::vector<std::string> wordList;
    
    // Helper methods
    void loadWordList() {
        // In a real implementation, this would load from files
        // For now, we'll hardcode some sample words for each category
        
        // Animals
        wordList.push_back("cat:animals:easy");
        wordList.push_back("dog:animals:easy");
        wordList.push_back("fish:animals:easy");
        wordList.push_back("elephant:animals:medium");
        wordList.push_back("giraffe:animals:medium");
        wordList.push_back("rhinoceros:animals:hard");
        wordList.push_back("hippopotamus:animals:hard");
        
        // Countries
        wordList.push_back("usa:countries:easy");
        wordList.push_back("peru:countries:easy");
        wordList.push_back("china:countries:easy");
        wordList.push_back("germany:countries:medium");
        wordList.push_back("australia:countries:medium");
        wordList.push_back("kazakhstan:countries:hard");
        wordList.push_back("switzerland:countries:hard");
        
        // Food
        wordList.push_back("pizza:food:easy");
        wordList.push_back("bread:food:easy");
        wordList.push_back("pasta:food:easy");
        wordList.push_back("hamburger:food:medium");
        wordList.push_back("spaghetti:food:medium");
        wordList.push_back("cheesecake:food:hard");
        wordList.push_back("brigadeiro:food:hard");
        
        // Sports
        wordList.push_back("golf:sports:easy");
        wordList.push_back("tennis:sports:easy");
        wordList.push_back("soccer:sports:easy");
        wordList.push_back("baseball:sports:medium");
        wordList.push_back("basketball:sports:medium");
        wordList.push_back("gymnastics:sports:hard");
        wordList.push_back("windsurfing:sports:hard");
        
        // Movies
        wordList.push_back("jaws:movies:easy");
        wordList.push_back("alien:movies:easy");
        wordList.push_back("frozen:movies:easy");
        wordList.push_back("ghostbusters:movies:medium");
        wordList.push_back("jurassic park:movies:medium");
        wordList.push_back("the shawshank redemption:movies:hard");
        wordList.push_back("the lord of the rings:movies:hard");
    }
    
    std::string getRandomWord() {
        if (wordList.empty()) {
            return "hangman"; // Default fallback
        }
        
        std::string randomEntry = wordList[rand() % wordList.size()];
        size_t firstColon = randomEntry.find(':');
        
        if (firstColon != std::string::npos) {
            return randomEntry.substr(0, firstColon);
        }
        
        return randomEntry;
    }
    
    std::string getRandomWordByCategory(Category cat) {
        std::string categoryStr;
        
        switch (cat) {
            case Category::ANIMALS:
                categoryStr = "animals";
                break;
            case Category::COUNTRIES:
                categoryStr = "countries";
                break;
            case Category::FOOD:
                categoryStr = "food";
                break;
            case Category::SPORTS:
                categoryStr = "sports";
                break;
            case Category::MOVIES:
                categoryStr = "movies";
                break;
            default:
                return getRandomWord();
        }
        
        std::vector<std::string> filteredWords;
        
        for (const auto& entry : wordList) {
            size_t firstColon = entry.find(':');
            size_t secondColon = entry.find(':', firstColon + 1);
            
            if (firstColon != std::string::npos && secondColon != std::string::npos) {
                std::string word = entry.substr(0, firstColon);
                std::string category = entry.substr(firstColon + 1, secondColon - firstColon - 1);
                
                if (category == categoryStr) {
                    filteredWords.push_back(word);
                }
            }
        }
        
        if (filteredWords.empty()) {
            return getRandomWord();
        }
        
        return filteredWords[rand() % filteredWords.size()];
    }
    
    std::string getRandomWordByDifficulty(Difficulty diff) {
        std::string difficultyStr;
        
        switch (diff) {
            case Difficulty::EASY:
                difficultyStr = "easy";
                break;
            case Difficulty::MEDIUM:
                difficultyStr = "medium";
                break;
            case Difficulty::HARD:
                difficultyStr = "hard";
                break;
        }
        
        std::vector<std::string> filteredWords;
        
        for (const auto& entry : wordList) {
            size_t firstColon = entry.find(':');
            size_t secondColon = entry.find(':', firstColon + 1);
            
            if (firstColon != std::string::npos && secondColon != std::string::npos) {
                std::string word = entry.substr(0, firstColon);
                std::string difficulty = entry.substr(secondColon + 1);
                
                if (difficulty == difficultyStr) {
                    filteredWords.push_back(word);
                }
            }
        }
        
        if (filteredWords.empty()) {
            return getRandomWord();
        }
        
        return filteredWords[rand() % filteredWords.size()];
    }
    
    void clearScreen() const {
        system(CLEAR);
    }
    
    std::string getCategoryName(Category category) const {
        switch (category) {
            case Category::ANIMALS: return "Animals";
            case Category::COUNTRIES: return "Countries";
            case Category::FOOD: return "Food";
            case Category::SPORTS: return "Sports";
            case Category::MOVIES: return "Movies";
            case Category::RANDOM: return "Random";
            default: return "Unknown";
        }
    }
    
    std::string getDifficultyName(Difficulty difficulty) const {
        switch (difficulty) {
            case Difficulty::EASY: return "Easy";
            case Difficulty::MEDIUM: return "Medium";
            case Difficulty::HARD: return "Hard";
            default: return "Unknown";
        }
    }
    
    void displayHangman(int attempts) const {
        std::vector<std::string> hangmanArt;
        
        // State 0: Game over
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "  /|\\  |\n"
            "  / \\  |\n"
            "       |\n"
            "=========");
        
        // State 1: One attempt left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "  /|\\  |\n"
            "  /    |\n"
            "       |\n"
            "=========");
        
        // State 2: Two attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "  /|\\  |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 3: Three attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "  /|   |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 4: Four attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "   |   |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 5: Five attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "   O   |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 6: Six attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "   |   |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 7: Seven attempts left
        hangmanArt.push_back(
            "   +---+\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // State 8: Eight attempts left
        hangmanArt.push_back(
            "       \n"
            "       |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "=========");
        
        // Display appropriate state
        int index = std::min(std::max(attempts, 0), 8);
        
        if (colorEnabled) {
            // Colorize the hangman based on attempts
            std::string hangmanStr = hangmanArt[attempts > 8 ? 8 : attempts];
            
            if (attempts <= 2) {
                // Red for danger
                std::cout << Color::RED << hangmanStr << Color::RESET << std::endl;
            } else if (attempts <= 4) {
                // Yellow for warning
                std::cout << Color::YELLOW << hangmanStr << Color::RESET << std::endl;
            } else {
                // Green for good
                std::cout << Color::GREEN << hangmanStr << Color::RESET << std::endl;
            }
        } else {
            std::cout << hangmanArt[attempts > 8 ? 8 : attempts] << std::endl;
        }
    }
    
    void displayTitle() const {
        clearScreen();
        
        if (colorEnabled) {
            std::cout << Color::CYAN << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << Color::RESET << std::endl;
            std::cout << Color::CYAN << "�U" << Color::RESET << Color::BOLD << Color::YELLOW << "            HANGMAN GAME            " << Color::RESET << Color::CYAN << "�U" << Color::RESET << std::endl;
            std::cout << Color::CYAN << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << Color::RESET << std::endl;
            std::cout << std::endl;
            std::cout << Color::MAGENTA << "Created by: Awesome Developer" << Color::RESET << std::endl;
            std::cout << Color::GREEN << "Version 2.0" << Color::RESET << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "=======================================" << std::endl;
            std::cout << "            HANGMAN GAME              " << std::endl;
            std::cout << "=======================================" << std::endl;
            std::cout << std::endl;
            std::cout << "Created by: Awesome Developer" << std::endl;
            std::cout << "Version 2.0" << std::endl;
            std::cout << std::endl;
        }
    }
    
    void displayLetterStatus() const {
        std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        
        std::cout << std::endl;
        if (colorEnabled) {
            std::cout << Color::CYAN << "Letters: " << Color::RESET;
        } else {
            std::cout << "Letters: ";
        }
        
        for (char letter : alphabet) {
            bool isGuessed = std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
            
            if (colorEnabled) {
                if (isGuessed) {
                    std::cout << Color::RED << letter << " " << Color::RESET;
                } else {
                    std::cout << Color::GREEN << letter << " " << Color::RESET;
                }
            } else {
                if (isGuessed) {
                    std::cout << "(" << letter << ") ";
                } else {
                    std::cout << letter << " ";
                }
            }
        }
        
        std::cout << std::endl << std::endl;
    }
    
    void displayInstructions() const {
        displayTitle();
        
        if (colorEnabled) {
            std::cout << Color::BOLD << "Instructions:" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "- Choose a difficulty level and word category." << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "- Guess one letter at a time." << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "- Each incorrect guess adds a part to the hangman." << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "- If the hangman is completed before you guess the word, you lose." << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "- Press " << Color::GREEN << "'!'" << Color::YELLOW << " to toggle color mode." << Color::RESET << std::endl;
        } else {
            std::cout << "Instructions:" << std::endl;
            std::cout << "- Choose a difficulty level and word category." << std::endl;
            std::cout << "- Guess one letter at a time." << std::endl;
            std::cout << "- Each incorrect guess adds a part to the hangman." << std::endl;
            std::cout << "- If the hangman is completed before you guess the word, you lose." << std::endl;
            std::cout << "- Press '!' to toggle color mode." << std::endl;
        }
        
        std::cout << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
    
    Difficulty getDifficultyChoice() const {
        int choice;
        
        if (colorEnabled) {
            std::cout << Color::CYAN << "Select difficulty:" << Color::RESET << std::endl;
            std::cout << Color::GREEN << "1. " << Color::WHITE << "Easy" << Color::RESET << " (8 attempts, shorter words)" << std::endl;
            std::cout << Color::YELLOW << "2. " << Color::WHITE << "Medium" << Color::RESET << " (6 attempts, medium words)" << std::endl;
            std::cout << Color::RED << "3. " << Color::WHITE << "Hard" << Color::RESET << " (4 attempts, longer words)" << std::endl;
            std::cout << Color::CYAN << "Enter your choice " << Color::YELLOW << "(1-3)" << Color::CYAN << ": " << Color::RESET;
        } else {
            std::cout << "Select difficulty:" << std::endl;
            std::cout << "1. Easy (8 attempts, shorter words)" << std::endl;
            std::cout << "2. Medium (6 attempts, medium words)" << std::endl;
            std::cout << "3. Hard (4 attempts, longer words)" << std::endl;
            std::cout << "Enter your choice (1-3): ";
        }
        
        std::cin >> choice;
        
        // Input validation
        while (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            
            if (colorEnabled) {
                std::cout << Color::RED << "Invalid choice. Please enter 1, 2, or 3: " << Color::RESET;
            } else {
                std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
            }
            
            std::cin >> choice;
        }
        
        switch (choice) {
            case 1: return Difficulty::EASY;
            case 2: return Difficulty::MEDIUM;
            case 3: return Difficulty::HARD;
            default: return Difficulty::MEDIUM;
        }
    }
    
    Category getCategoryChoice() const {
        int choice;
        
        if (colorEnabled) {
            std::cout << Color::CYAN << "Select word category:" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "1. " << Color::WHITE << "Animals" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "2. " << Color::WHITE << "Countries" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "3. " << Color::WHITE << "Food" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "4. " << Color::WHITE << "Sports" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "5. " << Color::WHITE << "Movies" << Color::RESET << std::endl;
            std::cout << Color::YELLOW << "6. " << Color::WHITE << "Random" << Color::RESET << std::endl;
            std::cout << Color::CYAN << "Enter your choice " << Color::YELLOW << "(1-6)" << Color::CYAN << ": " << Color::RESET;
        } else {
            std::cout << "Select word category:" << std::endl;
            std::cout << "1. Animals" << std::endl;
            std::cout << "2. Countries" << std::endl;
            std::cout << "3. Food" << std::endl;
            std::cout << "4. Sports" << std::endl;
            std::cout << "5. Movies" << std::endl;
            std::cout << "6. Random" << std::endl;
            std::cout << "Enter your choice (1-6): ";
        }
        
        std::cin >> choice;
        
        // Input validation
        while (std::cin.fail() || choice < 1 || choice > 6) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            
            if (colorEnabled) {
                std::cout << Color::RED << "Invalid choice. Please enter a number between 1 and 6: " << Color::RESET;
            } else {
                std::cout << "Invalid choice. Please enter a number between 1 and 6: ";
            }
            
            std::cin >> choice;
        }
        
        switch (choice) {
            case 1: return Category::ANIMALS;
            case 2: return Category::COUNTRIES;
            case 3: return Category::FOOD;
            case 4: return Category::SPORTS;
            case 5: return Category::MOVIES;
            case 6: return Category::RANDOM;
            default: return Category::RANDOM;
        }
    }
    
    char getLetterGuess() const {
        char guess;
        bool validInput = false;
        
        while (!validInput) {
            if (colorEnabled) {
                std::cout << Color::YELLOW << "Enter a letter (or '!' to toggle colors): " << Color::RESET;
            } else {
                std::cout << "Enter a letter (or '!' to toggle colors): ";
            }
            
            std::cin >> guess;
            guess = std::tolower(guess);
            
            if (guess == '!') {
                return guess; // Special command
            }
            
            if (std::isalpha(guess)) {
                validInput = true;
            } else {
                if (colorEnabled) {
                    std::cout << Color::RED << "Invalid input! Please enter a letter." << Color::RESET << std::endl;
                } else {
                    std::cout << "Invalid input! Please enter a letter." << std::endl;
                }
            }
        }
        
        return guess;
    }
    
    bool getPlayAgainChoice() const {
        char choice;
        
        if (colorEnabled) {
            std::cout << Color::YELLOW << "Would you like to play again? (y/n): " << Color::RESET;
        } else {
            std::cout << "Would you like to play again? (y/n): ";
        }
        
        std::cin >> choice;
        
        return (choice == 'y' || choice == 'Y');
    }
    
    void displayCurrentState() {
        displayTitle();
        
        // Display difficulty and category
        if (colorEnabled) {
            std::cout << Color::CYAN << "Difficulty: " << Color::RESET;
            
            std::string diffName = getDifficultyName(difficulty);
            if (difficulty == Difficulty::EASY) {
                std::cout << Color::GREEN << diffName << Color::RESET;
            } else if (difficulty == Difficulty::MEDIUM) {
                std::cout << Color::YELLOW << diffName << Color::RESET;
            } else {
                std::cout << Color::RED << diffName << Color::RESET;
            }
            
            std::cout << "   " << Color::CYAN << "Category: " << Color::MAGENTA 
                      << getCategoryName(category) << Color::RESET << std::endl;
        } else {
            std::cout << "Difficulty: " << getDifficultyName(difficulty)
                      << "   Category: " << getCategoryName(category) << std::endl;
        }
        
        std::cout << std::endl;
        
        // Display hangman
        displayHangman(attemptsLeft);
        
        // Display current word state
        std::cout << std::endl;
        if (colorEnabled) {
            std::cout << Color::CYAN << "Word: " << Color::BOLD << Color::WHITE 
                      << getDisplayWord() << Color::RESET << std::endl;
        } else {
            std::cout << "Word: " << getDisplayWord() << std::endl;
        }
        
        // Display attempts left
        std::cout << std::endl;
        if (colorEnabled) {
            std::cout << "Attempts left: ";
            if (attemptsLeft <= 2) {
                std::cout << Color::RED << attemptsLeft << Color::RESET;
            } else if (attemptsLeft <= 4) {
                std::cout << Color::YELLOW << attemptsLeft << Color::RESET;
            } else {
                std::cout << Color::GREEN << attemptsLeft << Color::RESET;
            }
            std::cout << std::endl;
        } else {
            std::cout << "Attempts left: " << attemptsLeft << std::endl;
        }
        
        // Display guessed letters
        displayLetterStatus();
    }
    
    void displayGameOver() {
        clearScreen();
        
        // Display final hangman state
        displayHangman(attemptsLeft);
        
        std::cout << std::endl;
        
        if (gameWon) {
            if (colorEnabled) {
                std::cout << Color::GREEN << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << Color::RESET << std::endl;
                std::cout << Color::GREEN << "�U" << Color::BOLD << Color::YELLOW << "  CONGRATULATIONS! YOU GUESSED THE WORD  " << Color::RESET << Color::GREEN << "�U" << Color::RESET << std::endl;
                std::cout << Color::GREEN << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << Color::RESET << std::endl;
                std::cout << std::endl;
                std::cout << Color::CYAN << "The word was: " << Color::BOLD << Color::WHITE << word << Color::RESET << std::endl;
            } else {
                std::cout << "==========================================" << std::endl;
                std::cout << "  CONGRATULATIONS! YOU GUESSED THE WORD  " << std::endl;
                std::cout << "==========================================" << std::endl;
                std::cout << std::endl;
                std::cout << "The word was: " << word << std::endl;
            }
        } else {
            if (colorEnabled) {
                std::cout << Color::RED << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << Color::RESET << std::endl;
                std::cout << Color::RED << "�U" << Color::BOLD << Color::YELLOW << "        GAME OVER! YOU LOST!            " << Color::RESET << Color::RED << "�U" << Color::RESET << std::endl;
                std::cout << Color::RED << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << Color::RESET << std::endl;
                std::cout << std::endl;
                std::cout << Color::CYAN << "The word was: " << Color::BOLD << Color::WHITE << word << Color::RESET << std::endl;
            } else {
                std::cout << "==========================================" << std::endl;
                std::cout << "        GAME OVER! YOU LOST!            " << std::endl;
                std::cout << "==========================================" << std::endl;
                std::cout << std::endl;
                std::cout << "The word was: " << word << std::endl;
            }
        }
        
        std::cout << std::endl;
    }
    
public:
    // Constructor
    HangmanGame(bool useColor = true) : attemptsLeft(6), 
                                     difficulty(Difficulty::MEDIUM), 
                                     category(Category::RANDOM),
                                     gameOver(false), gameWon(false),
                                     colorEnabled(useColor) {
        loadWordList();
        initialize();
    }
    
    // Initialize the game
    void initialize() {
        guessedLetters.clear();
        gameOver = false;
        gameWon = false;
        
        // Get a random word based on settings
        if (category == Category::RANDOM) {
            word = getRandomWord();
        } else {
            word = getRandomWordByCategory(category);
        }
        
        // Apply difficulty filter if needed
        if (word.length() < 4 || 
            (difficulty == Difficulty::EASY && word.length() > 6) ||
            (difficulty == Difficulty::MEDIUM && (word.length() < 7 || word.length() > 9))) {
            word = getRandomWordByDifficulty(difficulty);
        }
        
        // Convert to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        // Set attempts based on difficulty
        switch (difficulty) {
            case Difficulty::EASY:
                attemptsLeft = 8;
                break;
            case Difficulty::MEDIUM:
                attemptsLeft = 6;
                break;
            case Difficulty::HARD:
                attemptsLeft = 4;
                break;
        }
    }
    
    // Make a guess
    bool makeGuess(char letter) {
        // Convert to lowercase
        letter = std::tolower(letter);
        
        // Check if already guessed
        if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            return false;
        }
        
        // Add to guessed letters
        guessedLetters.push_back(letter);
        
        // Check if letter is in the word
        if (word.find(letter) == std::string::npos) {
            attemptsLeft--;
            
            // Check for game over
            if (attemptsLeft <= 0) {
                gameOver = true;
            }
            
            return false;
        }
        
        // Check for win
        bool allLettersGuessed = true;
        for (char c : word) {
            if (std::isalpha(c) && 
                std::find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
                allLettersGuessed = false;
                break;
            }
        }
        
        if (allLettersGuessed) {
            gameWon = true;
            gameOver = true;
        }
        
        return true;
    }
    
    // Toggle color mode
    void toggleColor() {
        colorEnabled = !colorEnabled;
        clearScreen();
        
        if (colorEnabled) {
            std::cout << Color::GREEN << "Color mode enabled!" << Color::RESET << std::endl;
        } else {
            std::cout << "Color mode disabled!" << std::endl;
        }
        
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
    
    // Get display version of the word (with underscores for hidden letters)
    std::string getDisplayWord() const {
        std::string display;
        
        for (char c : word) {
            if (std::isspace(c)) {
                display += " ";
            } else if (std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
                display += c;
            } else {
                display += "_";
            }
            display += " ";
        }
        
        return display;
    }
    
    // Game flow
    void playGame() {
        displayInstructions();
        
        bool playAgain = true;
        while (playAgain) {
            // Get game settings
            difficulty = getDifficultyChoice();
            category = getCategoryChoice();
            
            // Initialize with chosen settings
            initialize();
            
            // Game loop
            while (!gameOver) {
                displayCurrentState();
                
                // Get player's guess
                char guess = getLetterGuess();
                
                // Special command: toggle color mode
                if (guess == '!') {
                    toggleColor();
                    continue;
                }
                
                // Make the guess
                makeGuess(guess);
            }
            
            // Display game result
            displayGameOver();
            
            // Ask to play again
            playAgain = getPlayAgainChoice();
        }
        
        std::cout << "Thanks for playing Hangman!" << std::endl;
    }
    
    // Setters
    void setDifficulty(Difficulty diff) {
        difficulty = diff;
    }
    
    void setCategory(Category cat) {
        category = cat;
    }
    
    // Getters
    bool isGameOver() const {
        return gameOver;
    }
    
    bool isGameWon() const {
        return gameWon;
    }
};

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // Create and play the game
    HangmanGame game(true); // Start with color enabled
    game.playGame();
    
    return 0;
}