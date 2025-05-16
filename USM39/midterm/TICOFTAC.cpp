#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<char>& board) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i * 3 + j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<char>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) ||
            (board[i] == player && board[i + 3] == player && board[i + 6] == player)) {
            return true;
        }
    }
    return (board[0] == player && board[4] == player && board[8] == player) ||
           (board[2] == player && board[4] == player && board[6] == player);
}

int main() {
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    int moves = 0;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Instructions: Players take turns to place their mark (X or O) on the board.\n";
    cout << "The first player to align three marks in a row, column, or diagonal wins.\n";
    cout << "Enter a number (1-9) to place your mark. The positions are as follows:\n";
    cout << "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9\n";

    while (moves < 9) {
        printBoard(board);
        int choice;
        cout << "Player " << currentPlayer << ", enter your choice: ";
        cin >> choice;
        choice--; // Adjust for 0-based index
        
        if (choice < 0 || choice > 8 || board[choice] != ' ') {
            cout << "Invalid move, try again.\n";
            continue;
        }

        board[choice] = currentPlayer;
        moves++;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    cout << "It's a draw!\n";
    return 0;
}
