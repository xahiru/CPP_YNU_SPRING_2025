/*
* Snake Game - Console Implementation
 * School of Software, Yunnan University
 * Mid-Term Assignment - Programming Language and C++ Practice
 * Name: Tuhin Md Abu Hamza
 * ID: 20233120013
 */

// Include necessary headers
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>

// Platform-specific headers
#ifdef _WIN32
    #include <conio.h>  // Windows console I/O
    #include <windows.h>
#else
    #include <unistd.h>  // UNIX sleep
    #include <termios.h> // UNIX terminal control
    #include <fcntl.h>   // UNIX file control
#endif

using namespace std;

// Game state variables
bool gameOver;
const int width = 20;   // Game board width
const int height = 20;  // Game board height
int x, y;               // Head position
int fruitX, fruitY;     // Food position
int score;              // Player score
vector<pair<int, int>> snake; // Snake body segments
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;         // Current direction

// Cross-platform input functions
#ifdef _WIN32
int kbhit() { return _kbhit(); }
int getch() { return _getch(); }
#else
// UNIX implementation of kbhit()
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// UNIX implementation of getch()
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

// Initialize game state
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    snake.clear();
    snake.push_back({x, y});
}

// Render game frame
void Draw() {
    // Clear screen (platform-specific)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Game instructions
    cout << "Snake Game - Controls:" << endl;
    cout << "W - Up, A - Left, S - Down, D - Right" << endl;
    cout << "X - Quit Game" << endl << endl;

    // Draw top border
    for(int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    // Draw game area
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
                cout << "#"; // Left border
            
            bool isSnakeSegment = false;
            // Draw snake head (O) and body (o)
            for(auto segment : snake) {
                if(segment.first == j && segment.second == i) {
                    if(segment == snake[0])
                        cout << "O"; // Head
                    else
                        cout << "o"; // Body
                    isSnakeSegment = true;
                    break;
                }
            }
            
            // Draw food or empty space
            if(!isSnakeSegment) {
                if(i == fruitY && j == fruitX)
                    cout << "F"; // Food
                else
                    cout << " ";
            }

            if(j == width-1)
                cout << "#"; // Right border
        }
        cout << endl;
    }

    // Draw bottom border
    for(int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    // Display score
    cout << "Score: " << score << endl;
}

// Handle keyboard input
void Input() {
    if(kbhit()) {
        switch(getch()) {
            case 'a':
                if(dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if(dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if(dir != DOWN) dir = UP;
                break;
            case 's':
                if(dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

// Update game state
void Logic() {
    // Store previous head position
    pair<int, int> prevHead = snake[0];
    
    // Move head based on direction
    switch(dir) {
        case LEFT:
            snake[0].first--;
            break;
        case RIGHT:
            snake[0].first++;
            break;
        case UP:
            snake[0].second--;
            break;
        case DOWN:
            snake[0].second++;
            break;
        default:
            break;
    }
    
    // Wall collision detection
    if(snake[0].first >= width || snake[0].first < 0 || 
       snake[0].second >= height || snake[0].second < 0) {
        gameOver = true;
    }
    
    // Self-collision detection
    for(size_t i = 1; i < snake.size(); i++) {
        if(snake[0] == snake[i]) {
            gameOver = true;
        }
    }
    
    // Food consumption check
    if(snake[0].first == fruitX && snake[0].second == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        snake.push_back(snake.back()); // Grow snake
    } else {
        // Move body segments
        for(size_t i = snake.size()-1; i > 0; i--) {
            snake[i] = snake[i-1];
        }
    }
}

// Main game loop
int main() {
    srand(time(0)); // Seed random number generator
    Setup();
    
    while(!gameOver) {
        Draw();
        Input();
        Logic();
        
        // Frame delay (platform-specific)
        #ifdef _WIN32
            Sleep(100); // 100ms delay on Windows
        #else
            usleep(100000); // 100ms delay on UNIX
        #endif
    }
    
    // Game over message
    cout << "\nGame Over! Final Score: " << score << endl;
    cout << "Press any key to exit...";
    getch();
    
    return 0;
}