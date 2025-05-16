#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
int scoreX = 0, scoreO = 0;

// Function declarations
void printInstructions();
void resetBoard();
void displayBoard();
bool makeMove(char player);
bool checkWin(char player);
bool checkDraw();
void updateScore(char winner);
void showScore();

int main() {
    char currentPlayer = 'X';
    char playAgain;

    printInstructions();

    do {
        resetBoard();
        bool gameOver = false;
        currentPlayer = 'X';

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << "'s turn." << endl;

            if (makeMove(currentPlayer)) {
                if (checkWin(currentPlayer)) {
                    displayBoard();
                    cout << "🎉 Player " << currentPlayer << " wins!" << endl;
                    updateScore(currentPlayer);
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        showScore();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}

void printInstructions() {
    cout << "=== TIC-TAC-TOE GAME ===" << endl;
    cout << "Two players take turns to mark spaces in a 3x3 grid." << endl;
    cout << "Enter row and column numbers (1 to 3) to place your mark." << endl;
    cout << "First to get 3 in a row (horizontally, vertically, or diagonally) wins." << endl;
    cout << "Let's start!" << endl << endl;
}

void resetBoard() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = ' ';
}

void displayBoard() {
    cout << "\n   1   2   3\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "  ---+---+---" << endl;
    }
    cout << endl;
}

bool makeMove(char player) {
    int row, col;
    cout << "Enter row (1-3): ";
    cin >> row;

    // Check for input failure
    if (cin.fail()) {
        cin.clear(); // clear error flag
        cin.ignore(10000, '\n'); // discard bad input
        cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        return false;
    }

    cout << "Enter column (1-3): ";
    cin >> col;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        return false;
    }

    if (row < 1 || row > 3 || col < 1 || col > 3) {
        cout << "Invalid position! Try again." << endl;
        return false;
    }

    if (board[row - 1][col - 1] != ' ') {
        cout << "Cell already taken! Try again." << endl;
        return false;
    }

    board[row - 1][col - 1] = player;
    return true;
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void updateScore(char winner) {
    if (winner == 'X') scoreX++;
    else if (winner == 'O') scoreO++;
}

void showScore() {
    cout << "\nScoreboard:" << endl;
    cout << "Player X: " << scoreX << endl;
    cout << "Player O: " << scoreO << endl << endl;
}
