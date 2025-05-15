###Tic-Tac-Toe Challenge - Compilation Instructions###
    #Windows
        1. Using MinGW (GCC for Windows)
            1. Install MinGW (if not already installed):
                1. Download from (https://www.mingw-w64.org/)
                2. Or use Chocolatey: choco install mingw
            2. Compile the game:
                1.  g++ tictactoe.cpp -o tictactoe.exe -static-libgcc -static-libstdc++
            3. Run the game
                1.tictactoe.exe
        2. Using Microsoft Visual Studio
            1. Create a new C++ Console Project
            2. Add the source file to your project
            3. Build and run (F5)
  
    #Linux
        1. Using GCC (most distributions)
            1. Install build tools (if needed):
                1. sudo apt update && sudo apt install build-essential  # Debian/Ubuntu
                2. sudo dnf install gcc-c++  # Fedora
            2. Compile the game:
                1. g++ tictactoe.cpp -o tictactoe -std=c++11
            3. Run the game
                1. ./tictactoe
    #macOS
        1. Using Clang (Xcode Command Line Tools)
            1. Install Xcode Command Line Tools (if needed):
                1. xcode-select --install
            2. Compile the game:
                1. clang++ tictactoe.cpp -o tictactoe -std=c++11
            3. Run the game:
                1. ./tictactoe

    #Alternative Compilers All platforms can use    
        1. Clang (replace g++ with clang++ in commands)
        2. CMake (create a CMakeLists.txt file for more complex builds)