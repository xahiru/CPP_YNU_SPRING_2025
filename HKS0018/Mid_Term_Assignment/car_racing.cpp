#include <iostream>
#include <vector>    // For using the vector container
#include <chrono>    // For time-related functions
#include <thread>
#include <cstdlib>
#include <ctime>
#include <termios.h> // For Linux/Mac terminal control
#include <unistd.h> // For Linux/Mac usleep()
#include <fcntl.h> // For Linux/Mac non-blocking input
//#include <conio.h>        // Windows-specific console I/O (_kbhit, _getch)

//handles cross-platform compatibility for keyboard input:
#ifdef _WIN32  // Windows-specific headers
#else
// Linux/Mac terminal control functions
int _kbhit() {
    struct termios oldt, newt;  // Non-blocking keyboard check for Linux/Mac
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Set non-blocking

    ch = getchar();           // Try to Read the character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int _getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();  // Read the character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

//Game Constants and Variables:
using namespace std;

const int ROAD_WIDTH = 3;  //Number of lanes
const int GAME_WIDTH = 10;  //Width of the game area
const int CAR_POSITION = 1; // Default car position 

int score = 0;        //displays current game score
int highScore = 0;    // Highest game score
bool gameOver = false; //Game state flag
int gameSpeed = 200; // Game speed

void clearScreen() {
#ifdef _WIN32         // Cross-platform screen clearing
                      // Windows claer command
    system("cls");
#else
    system("clear");   //Unix/Linux/Mac clear command
#endif
}

void drawRoad(vector<vector<char>>& road) {
    clearScreen();
    
    // Display scoreboard
    cout << "SCORE: " << score << " | HIGH SCORE: " << highScore << " | SPEED: " << (500 - gameSpeed)/5 << endl;
    cout << "CONTROLS: A (LEFT) | D (RIGHT) | Q (QUIT)" << endl;
    cout << string(GAME_WIDTH + 2, '-') << endl;
    
    // Draw each row of the road
    for (int i = 0; i < road.size(); i++) {
        cout << "|";
        for (int j = 0; j < road[i].size(); j++) {
            cout << road[i][j];
        }
        cout << "|" << endl;
    }
    cout << string(GAME_WIDTH + 2, '-') << endl;
}

void initializeRoad(vector<vector<char>>& road) {
    road.clear();  // Clear existing road
    // Create 10 empty rows
    for (int i = 0; i < 10; i++) {
        vector<char> row(GAME_WIDTH, ' ');
        road.push_back(row);
    }
}

void updateRoad(vector<vector<char>>& road, int& carLane) {
    // Move all rows down
    for (int i = road.size() - 1; i > 0; i--) {
        road[i] = road[i - 1];
    }
    

    //Game Logic Functions
    // Generate new top row with possible obstacle
    vector<char> newRow(GAME_WIDTH, ' ');
    if (rand() % 5 == 0) { // 20% chance of obstacle
        int obstacleLane = rand() % ROAD_WIDTH;
        for (int i = 0; i < GAME_WIDTH; i += ROAD_WIDTH) {
            if (i / ROAD_WIDTH == obstacleLane) {
                newRow[i] = '#';
                newRow[i+1] = '#';
                newRow[i+2] = '#';
            }
        }
    }
    road[0] = newRow;
    
    // Check for collision
    if (road[road.size() - 1][carLane * ROAD_WIDTH + 1] == '#') {
        gameOver = true;
    }
    
    // Update score
    score++;
    if (score > highScore) {
        highScore = score;
    }
    
    // Increase speed every 50 points
    if (score % 50 == 0 && gameSpeed > 50) {
        gameSpeed -= 10;
    }
}

void drawCar(vector<vector<char>>& road, int carLane) {
    int row = road.size() - 1;
    int col = carLane * ROAD_WIDTH;
    
    road[row][col] = '*';
    road[row][col+1] = '|';
    road[row][col+2] = '|';
    road[row][col+3] = '*';
}

//Game Menu and Instructions
void showInstructions() {
    clearScreen();
    cout << "=== CAR RACING GAME ===" << endl;
    cout << "INSTRUCTIONS:" << endl;
    cout << "1. Use A (left) and D (right) to move your car" << endl;
    cout << "2. Avoid the obstacles (###)" << endl;
    cout << "3. The game gets faster as you score more points" << endl;
    cout << "4. Press Q to quit during game" << endl;
    cout << "\nPress any key to return to menu...";
    _getch();
}

//Main Game loop
void gameLoop() {
    vector<vector<char>> road;  // The game road/map
    initializeRoad(road);
    int carLane = CAR_POSITION;
    score = 0;
    gameOver = false;
    gameSpeed = 200;
    
    while (!gameOver) {
        if (_kbhit()) {
            char key = _getch();
            key = tolower(key);
            
            if (key == 'a' && carLane > 0) {
                carLane--;
            } else if (key == 'd' && carLane < ROAD_WIDTH - 1) {
                carLane++;
            } else if (key == 'q') {
                gameOver = true;
                return;
            }
        }
        
        updateRoad(road, carLane);  // Update game state
        drawCar(road, carLane);     // Draw car in new position
        drawRoad(road);             // Redraw the entire road
        
        // Platform-specific delay
#ifdef _WIN32
        Sleep(gameSpeed);
#else
        usleep(gameSpeed * 1000);
#endif
    }
    
    // Game over screen
    cout << "GAME OVER! Final Score: " << score << endl;
    cout << "Press any key to return to menu...";
    _getch();
}

int main() {
    srand(time(0)); // Seed random number generator
    
    // Main menu loop
    while (true) {
        clearScreen();
        cout << "=== CAR RACING GAME ===" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quit" << endl;
        cout << "Select option (1-3): ";
        
        char choice = _getch();
        
        switch (choice) {
            case '1':
                gameLoop();   // Start the game
                break;
            case '2':
                showInstructions();   // Show instructions
                break;
            case '3':        // Exit the game 
                return 0;
            default:
                cout << "\nInvalid choice! Press any key to continue...";
                _getch();    // Wait for key press on invalid input
        }
    }
    
    return 0;
}