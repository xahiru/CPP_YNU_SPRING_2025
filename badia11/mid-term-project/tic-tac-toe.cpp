/*
Tic-Tac-Toe Game
----------------
Compilation Instructions:
To compile using g++:

    g++ -o tic_tac_toe tic_tac_toe.cpp

To run:
    ./tic_tac_toe      (Linux/macOS)
    tic_tac_toe.exe    (Windows)

*/

#include <iostream>
#include <limits>  // For input validation

#ifdef _WIN32
    #include <cstdlib> // For system("cls")
#else
    #include <unistd.h>
#endif

using namespace std;

// Game state management
char board[3][3];
char current_player;
bool is_draw;

// Score tracking
int player1_wins = 0;
int player2_wins = 0;
int total_draws = 0;

// Function prototypes
void display_instructions();
void initialize_board();
void render_board();
void process_turn();
bool game_active();
void show_scores();
void clear_display();

int main() {
    char replay;

    display_instructions();

    do {
        initialize_board();
        current_player = 'X';
        is_draw = false;

        while (game_active()) {
            clear_display();
            render_board();
            process_turn();
        }

        clear_display();
        render_board();

        // Update game results
        if (is_draw) {
            cout << "\nGame ended in a draw!\n";
            total_draws++;
        } else {
            if (current_player == 'X') {
                cout << "\nPlayer 2 (O) wins!\n";
                player2_wins++;
            } else {
                cout << "\nPlayer 1 (X) wins!\n";
                player1_wins++;
            }
        }

        show_scores();

        cout << "\nPlay again? (Y/N): ";
        cin >> replay;
        replay = toupper(replay);

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (replay == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe!\n";
    return 0;
}

void display_instructions() {
    cout << "=============================================\n"
         << "           TIC-TAC-TOE: Ultimate Edition    \n"
         << "=============================================\n\n"
         << "Game Rules:\n"
         << "- 2 players alternate turns\n"
         << "- Player 1: X | Player 2: O\n"
         << "- Enter 1-9 to place your mark\n"
         << "- First with 3 in a row (any direction) wins\n"
         << "- Full board with no winner = draw\n\n";
}

void initialize_board() {
    char cell_value = '1';
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = cell_value++;
        }
    }
}

void render_board() {
    cout << "\nPlayer 1 [X]  vs  Player 2 [O]\n\n";
    for (int row = 0; row < 3; ++row) {
        cout << "     |     |     \n";
        cout << "  " << board[row][0] << "  |  " << board[row][1] << "  |  " << board[row][2] << "\n";
        if (row < 2) cout << "_____|_____|_____\n";
    }
    cout << "     |     |     \n\n";
}

void process_turn() {
    int input;
    int row, col;
    bool valid_move = false;

    while (!valid_move) {
        cout << "Player " << (current_player == 'X' ? "1 [X]" : "2 [O]") 
             << ", enter position (1-9): ";
             
        cin >> input;
        
        // Handle non-integer input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Numbers only.\n";
            continue;
        }

        // Convert input to board coordinates
        switch (input) {
            case 1: row = 0; col = 0; break;
            case 2: row = 0; col = 1; break;
            case 3: row = 0; col = 2; break;
            case 4: row = 1; col = 0; break;
            case 5: row = 1; col = 1; break;
            case 6: row = 1; col = 2; break;
            case 7: row = 2; col = 0; break;
            case 8: row = 2; col = 1; break;
            case 9: row = 2; col = 2; break;
            default:
                cout << "Invalid position! Use 1-9.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
        }

        // Check cell availability
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Position occupied! Try again.\n";
        } else {
            board[row][col] = current_player;
            current_player = (current_player == 'X') ? 'O' : 'X';
            valid_move = true;
        }
    }
}

bool game_active() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return false;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
        return false;
    }

    // Check for remaining moves
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                return true;
            }
        }
    }

    is_draw = true;
    return false;
}

void show_scores() {
    cout << "\n========== LEADERBOARD ==========\n"
         << " Player 1 Wins (X): " << player1_wins << "\n"
         << " Player 2 Wins (O): " << player2_wins << "\n"
         << " Total Draws:        " << total_draws << "\n"
         << "=================================\n";
}

void clear_display() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}