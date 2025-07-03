#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

class TicTacToe {
private:
    vector<vector<char>> board;
    int scores[2] = {0, 0};
    char currentPlayer;

    void clearScreen() {
        // Works well in VS Code terminal or Linux console
        cout << string(100, '\n');
    }

    void initializeBoard() {
        board = {
            {EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY}
        };
    }

    void displayBoard() {
        clearScreen();
        cout << "TIC-TAC-TOE GAME\n";
        cout << "Player X: " << scores[0] << " | Player O: " << scores[1] << "\n\n";
        
        cout << "    1   2   3\n";
        cout << "  +---+---+---+\n";
        for (int i = 0; i < 3; i++) {
            cout << i+1 << " | ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n  +---+---+---+\n";
        }
        cout << "\nCurrent player: " << currentPlayer << "\n\n";
    }

    bool isValidMove(int row, int col) {
        return row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == EMPTY;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY)
                    return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = PLAYER_X;
    }

    void displayInstructions() {
        clearScreen();
        cout << "TIC-TAC-TOE INSTRUCTIONS\n";
        cout << "------------------------\n";
        cout << "1. The game is played on a 3x3 grid.\n";
        cout << "2. Player X goes first, followed by Player O.\n";
        cout << "3. To make a move, enter the row and column numbers (1-3).\n";
        cout << "4. The first player to get 3 of their marks in a row wins.\n";
        cout << "5. If all squares are full with no winner, it's a tie.\n\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void playGame() {
        bool playAgain = true;
        
        while (playAgain) {
            initializeBoard();
            currentPlayer = PLAYER_X;
            bool gameOver = false;
            
            while (!gameOver) {
                displayBoard();
                
                int row, col;
                cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
                cin >> row >> col;
                
                if (!isValidMove(row, col)) {
                    cout << "Invalid move! Try again.\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    continue;
                }

                board[row-1][col-1] = currentPlayer;

                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    if (currentPlayer == PLAYER_X) scores[0]++;
                    else scores[1]++;
                    gameOver = true;
                } else if (isBoardFull()) {
                    displayBoard();
                    cout << "It's a tie!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }

            char choice;
            cout << "Would you like to play again? (y/n): ";
            cin >> choice;
            playAgain = (choice == 'y' || choice == 'Y');
        }

        clearScreen();
        cout << "FINAL SCORES:\n";
        cout << "Player X: " << scores[0] << "\n";
        cout << "Player O: " << scores[1] << "\n";
        cout << "Thanks for playing!\n";
    }
};

int main() {
    TicTacToe game;
    game.displayInstructions();
    game.playGame();
    return 0;
}
