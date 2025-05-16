#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

vector<char> board(9, ' ');
int playerScore = 0, aiScore = 0;

void printInstructions() {
    system(CLEAR);
    cout << "=== HOW TO PLAY ===\n";
    cout << "1. Enter positions (1-9) to place your mark (X).\n";
    cout << "2. AI (O) uses minimax algorithm and never loses.\n";
    cout << "3. Win by getting 3 in a row. Draw if the board fills.\n";
    cout << "Press Enter to start...";
    cin.ignore();
    cin.get();
}

void printHeader() {
    system(CLEAR);
    cout << "=== TIC-TAC-TOE ===\n";
    cout << "Player: X | AI: O\n";
    cout << "Score - Player: " << playerScore << " | AI: " << aiScore << "\n\n";
}

void printBoard() {
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    cout << "     |     |     \n\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i*3] == player && board[i*3+1] == player && board[i*3+2] == player) return true;
        if (board[i] == player && board[i+3] == player && board[i+6] == player) return true;
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    return false;
}

bool checkDraw() {
    for (char c : board) if (c == ' ') return false;
    return true;
}

int minimax(vector<char>& board, bool isMaximizing) {
    if (checkWin('O')) return 1;
    if (checkWin('X')) return -1;
    if (checkDraw()) return 0;

    int bestScore = isMaximizing ? -1000 : 1000;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = isMaximizing ? 'O' : 'X';
            int score = minimax(board, !isMaximizing);
            board[i] = ' ';
            bestScore = isMaximizing ? max(score, bestScore) : min(score, bestScore);
        }
    }
    return bestScore;
}

void aiMove() {
    int bestMove = -1, bestScore = -1000;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int score = minimax(board, false);
            board[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    if (bestMove != -1) board[bestMove] = 'O';
}

int main() {
    srand(time(0));
    bool playAgain = true;
    printInstructions();

    while (playAgain) {
        board = vector<char>(9, ' ');
        char currentPlayer = 'X';

        while (true) {
            printHeader();
            printBoard();

            if (currentPlayer == 'X') {
                int move;
                cout << "Enter position (1-9): ";
                if (!(cin >> move) || move < 1 || move > 9 || board[move-1] != ' ') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid move! ";
                    continue;
                }
                board[move-1] = 'X';
            } else {
                aiMove();
            }

            if (checkWin(currentPlayer)) {
                printHeader();
                printBoard();
                cout << (currentPlayer == 'X' ? "Player wins!" : "AI wins!") << endl;
                if (currentPlayer == 'X') playerScore++;
                else aiScore++;
                break;
            } else if (checkDraw()) {
                printHeader();
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        playAgain = (tolower(choice) == 'y');
    }

    return 0;
}