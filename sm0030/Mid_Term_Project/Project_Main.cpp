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



