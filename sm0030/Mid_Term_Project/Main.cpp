#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

enum PlayerType { HUMAN, AI };

struct GameState {
    vector<vector<char>> board;
    char currentPlayer;
    PlayerType typeX;
    PlayerType typeO;
    int scoreX;
    int scoreO;
    int ties;
};

void initializeGame(GameState& game);
void displayInstructions();
void displayBoard(const GameState& game);
void displayScores(const GameState& game);
bool makeMove(GameState& game, int position);
bool checkWin(const GameState& game);
bool checkTie(const GameState& game);
void switchPlayer(GameState& game);
void clearScreen();
void playGame(GameState& game);
bool askToPlayAgain();
int getPlayerMove(const GameState& game);
int getAIMove(const GameState& game);
string coloredChar(char c);
PlayerType selectPlayerType(char playerSymbol);

int main() {
    srand(static_cast<unsigned>(time(0)));

    GameState game;

    displayInstructions();
    game.typeX = selectPlayerType(PLAYER_X);
    game.typeO = selectPlayerType(PLAYER_O);

    do {
        initializeGame(game);
        playGame(game);
    } while (askToPlayAgain());

    cout << "\nThanks for playing Tic-Tac-Toe!\n";
    return 0;
}

void initializeGame(GameState& game) {
    game.board = vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
    game.currentPlayer = PLAYER_X;

    static bool firstGame = true;
    if (firstGame) {
        game.scoreX = 0;
        game.scoreO = 0;
        game.ties = 0;
        firstGame = false;
    }
}

void displayInstructions() {
    clearScreen();
    cout << "Welcome to Tic-Tac-Toe!\n\n";
    cout << "Instructions:\n";
    cout << "1. The game is played on a 3x3 grid (positions 1-9).\n";
    cout << "2. Players take turns to place their marks.\n";
    cout << "3. First to get 3 in a row wins!\n\n";
    cout << "    1 | 2 | 3\n";
    cout << "   ---+---+---\n";
    cout << "    4 | 5 | 6\n";
    cout << "   ---+---+---\n";
    cout << "    7 | 8 | 9\n\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    clearScreen();
}

PlayerType selectPlayerType(char playerSymbol) {
    char choice;
    cout << "Choose player type for " << playerSymbol << " (h = human, a = AI): ";
    cin >> choice;
    return (choice == 'a' || choice == 'A') ? AI : HUMAN;
}

string coloredChar(char c) {
    if (c == PLAYER_X)
        return "\033[32mX\033[0m";  // Green
    else if (c == PLAYER_O)
        return "\033[31mO\033[0m";  // Red
    else
        return " ";
}

void displayBoard(const GameState& game) {
    cout << "\nCurrent Board:\n\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "   ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << " " << coloredChar(game.board[i][j]) << " ";
            if (j < 2) cout << "│";
        }
        cout << "\n";
        if (i < 2) cout << "   ───┼───┼───\n";
    }
    cout << "\n";
}

void displayScores(const GameState& game) {
    cout << "Score Board:\n";
    cout << "Player \033[32mX\033[0m: " << game.scoreX << " wins\n";
    cout << "Player \033[31mO\033[0m: " << game.scoreO << " wins\n";
    cout << "Ties: " << game.ties << "\n\n";
}

bool makeMove(GameState& game, int position) {
    if (position < 1 || position > 9) return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (game.board[row][col] != EMPTY) return false;

    game.board[row][col] = game.currentPlayer;
    return true;
}

bool checkWin(const GameState& game) {
    const char p = game.currentPlayer;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((game.board[i][0] == p && game.board[i][1] == p && game.board[i][2] == p) ||
            (game.board[0][i] == p && game.board[1][i] == p && game.board[2][i] == p))
            return true;
    }

    if ((game.board[0][0] == p && game.board[1][1] == p && game.board[2][2] == p) ||
        (game.board[0][2] == p && game.board[1][1] == p && game.board[2][0] == p))
        return true;

    return false;
}

bool checkTie(const GameState& game) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (game.board[i][j] == EMPTY)
                return false;
    return true;
}

void switchPlayer(GameState& game) {
    game.currentPlayer = (game.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getPlayerMove(const GameState& game) {
    int position;
    cout << "Player " << (game.currentPlayer == PLAYER_X ? "\033[32mX\033[0m" : "\033[31mO\033[0m") << "'s turn.\n";
    cout << "Enter position (1-9): ";
    cin >> position;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return position;
}

int getAIMove(const GameState& game) {
    vector<int> available;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        int row = i / 3;
        int col = i % 3;
        if (game.board[row][col] == EMPTY)
            available.push_back(i + 1);
    }

    if (available.empty()) return -1;

    return available[rand() % available.size()];
}

void playGame(GameState& game) {
    clearScreen();
    bool gameOver = false;

    while (!gameOver) {
        displayScores(game);
        displayBoard(game);

        int move;
        if ((game.currentPlayer == PLAYER_X && game.typeX == AI) ||
            (game.currentPlayer == PLAYER_O && game.typeO == AI)) {
            move = getAIMove(game);
            cout << "AI chooses position: " << move << endl;
        } else {
            move = getPlayerMove(game);
        }

        if (makeMove(game, move)) {
            if (checkWin(game)) {
                clearScreen();
                displayScores(game);
                displayBoard(game);
                cout << "Player " << (game.currentPlayer == PLAYER_X ? "\033[32mX\033[0m" : "\033[31mO\033[0m") << " wins!\n";
                (game.currentPlayer == PLAYER_X) ? game.scoreX++ : game.scoreO++;
                gameOver = true;
            } else if (checkTie(game)) {
                clearScreen();
                displayScores(game);
                displayBoard(game);
                cout << "The game is a tie!\n";
                game.ties++;
                gameOver = true;
            } else {
                switchPlayer(game);
                clearScreen();
            }
        } else {
            if ((game.currentPlayer == PLAYER_X && game.typeX == HUMAN) ||
                (game.currentPlayer == PLAYER_O && game.typeO == HUMAN)) {
                cout << "Invalid move. Try again.\n";
            }
        }
    }
}

bool askToPlayAgain() {
    char response;
    cout << "\nWould you like to play again? (y/n): ";
    cin >> response;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return (response == 'y' || response == 'Y');
}
