#include <iostream> // for input and output
#include <array> // for array data structure
#include <string> // for string manipulation
#include <algorithm> // for algorithms
#include <limits> // for numeric limits 

#ifdef _WIN32 // check if the OS is Windows
#include <windows.h> // for Windows-specific functions
#define CLEAR "cls" // command to clear the console in Windows
#else  // for other operating systems
#include <unistd.h> // for Unix-specific functions
#define CLEAR "clear" // command to clear the console in Unix
#endif // end of OS check

using namespace std; // to avoid using std:: prefix

// Clear terminal screen
void clearDisplay() {
    system(CLEAR);
}

// Show game board
void renderBoard(const array<array<char, 3>, 3>& grid) {
    clearDisplay();
    cout << "Tic-Tac-Toe Challenge\n";
    cout << "Player 1 [X] --- Player 2 [O]\n\n";
    
    for (int i = 0; i < 3; ++i) {
        cout << "     |     |     \n";
        cout << "  " << (grid[i][0] == ' ' ? ' ' : grid[i][0]) << "  |  " 
             << (grid[i][1] == ' ' ? ' ' : grid[i][1]) << "  |  " 
             << (grid[i][2] == ' ' ? ' ' : grid[i][2]) << "  \n";
        if (i < 2) cout << "_____|_____|_____\n";
    }
    cout << "     |     |     \n\n";
}

// Verify winning condition
bool verifyVictory(const array<array<char, 3>, 3>& grid, char symbol) {
    // Check horizontal and vertical lines
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
            return true;
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
            return true;
    }
    // Check diagonals
    return (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
           (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol);
}

// Check for tied game
bool verifyTie(const array<array<char, 3>, 3>& grid) {
    for (const auto& row : grid) {
        for (char c : row) {
            if (c == ' ') return false;
        }
    }
    return true;
}

// Display game guide
void displayGuide() {
    clearDisplay();
    cout << "Tic-Tac-Toe Game Manual\n";
    cout << "======================\n";
    cout << "1. Grid contains 3x3 positions\n";
    cout << "2. Player 1 uses X, Player 2 uses O\n";
    cout << "3. Select position by entering 1-9 as shown below:\n\n";
    
    cout << "     |     |     \n";
    cout << "  1  |  2  |  3  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  4  |  5  |  6  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  7  |  8  |  9  \n";
    cout << "     |     |     \n\n";
    
    cout << "4. First to align 3 symbols wins\n";
    cout << "5. Full grid with no alignment results in tie\n\n";
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Show current standings
void displayStandings(int xWins, int oWins, int ties) {
    clearDisplay();
    cout << "Current Standings\n";
    cout << "=================\n";
    cout << "Player 1 (X): " << xWins << " victories\n";
    cout << "Player 2 (O): " << oWins << " victories\n";
    cout << "Tied matches: " << ties << "\n\n";
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Execute game round
void executeRound(int& xWins, int& oWins, int& ties) {
    array<array<char, 3>, 3> grid = {{{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}}};
    char activePlayer = 'X';
    bool roundActive = true;

    while (roundActive) {
        renderBoard(grid);
        int selection;
        bool validSelection = false;

        while (!validSelection) {
            cout << "Player " << (activePlayer == 'X' ? "1 (X)" : "2 (O)") 
                 << ", make your move (1-9): ";
            if (!(cin >> selection)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            if (selection < 1 || selection > 9) {
                cout << "Invalid number! Please enter 1-9.\n";
                continue;
            }

            int row = (selection - 1) / 3;
            int col = (selection - 1) % 3;

            if (grid[row][col] != ' ') {
                cout << "Position occupied! Try another.\n";
            } else {
                grid[row][col] = activePlayer;
                validSelection = true;
            }
        }

        if (verifyVictory(grid, activePlayer)) {
            renderBoard(grid);
            cout << "Player " << (activePlayer == 'X' ? "1 (X)" : "2 (O)") 
                 << " wins!\n";
            activePlayer == 'X' ? xWins++ : oWins++;
            roundActive = false;
        } else if (verifyTie(grid)) {
            renderBoard(grid);
            cout << "Game ends in tie!\n";
            ties++;
            roundActive = false;
        } else {
            activePlayer = (activePlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Main application loop
int main() {
    int xWins = 0, oWins = 0, ties = 0; // initialize scores
    bool appRunning = true; 

    // flag for main loop
    while (appRunning) {
        clearDisplay();
        cout << "Tic-Tac-Toe Main Menu\n";
        cout << "=====================\n";
        cout << "1. Start New Game\n";
        cout << "2. View Game Manual\n";
        cout << "3. Check Scores\n";
        cout << "4. Exit Game\n";
        cout << "Enter your choice (1-4): ";

        int option;
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            #ifdef _WIN32
            Sleep(1500);
            #else
            sleep(1);
            #endif
            continue;
        }
        // Check if option is valid
        switch (option) {
            case 1: executeRound(xWins, oWins, ties); break;
            case 2: displayGuide(); break;
            case 3: displayStandings(xWins, oWins, ties); break;
            case 4: appRunning = false; break;
            default:
                cout << "Invalid option! Please enter 1-4.\n";
                #ifdef _WIN32
                Sleep(1500);
                #else
                sleep(1);
                #endif
        }
    }

    clearDisplay();
    cout << "Game Over\n";
    cout << "Final Scores:\n";
    cout << "Player 1 (X): " << xWins << " wins\n";
    cout << "Player 2 (O): " << oWins << " wins\n";
    cout << "Tied games: " << ties << "\n\n";

    return 0;
}