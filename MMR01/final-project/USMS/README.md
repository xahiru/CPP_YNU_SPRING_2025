A comprehensive C++ application for managing university students, faculty, courses, enrollments, and grades.

# Features
Student Management: Add, remove, view, and update student records.
Faculty Management: Add, remove, and view faculty information.
Course Management: Create, delete, and manage courses.
Enrollment Management: Enroll/drop students from courses.
Grade Management: Record and update student grades.
Reporting: Generate student and course reports.
Data Persistence: Automatic saving to text files.

# Compilation Instructions
Prerequisites
C++17 compatible compiler
Make (for Unix-like systems)
CMake (optional)

# Windows
Using MinGW (Recommended):
g++ -std=c++17 main.cpp -o main
main.exe
Using Visual Studio:

Create a new C++ Console Application project.
Add the source file (main.cpp).
Build and run the project.

# macOS
Install compiler if needed (Xcode Command Line Tools):
xcode-select --install
Compile:
g++ -std=c++17 main.cpp -o main
Run:
./main

# Linux
Install build essentials (if needed):
sudo apt-get install build-essential  # Ubuntu/Debian
sudo dnf install gcc-c++ make          # Fedora
Compile:
g++ -std=c++17 main.cpp -o main
Run:
./main

# CMake Support (Optional)
Create a CMakeLists.txt file:

cmake_minimum_required(VERSION 3.10)
project(USMS)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
Then build:

mkdir build
cd build
cmake ..
cmake --build .


# File Structure
.
├── data/               # Directory for data files (auto-created)
│   ├── students.txt    # Student records
│   ├── faculty.txt     # Faculty records
│   └── courses.txt     # Course records
├── main.cpp            # Main source file
└── README.md           # This file


# Usage
Run the executable.
Follow the on-screen menu:
Student Management
Faculty Management
Course Management
Enrollment Management
Grade Management
Reports
Exit (saves data)


# Notes

The program automatically creates a data directory and saves all records to text files.
Data is saved when:
Explicitly choosing to exit (option 8).
The program terminates normally.
For Linux/Mac, you may need to make the executable executable:
chmod +x main


# Troubleshooting

Permission Denied Errors:
On Linux/Mac: chmod +x main
Ensure you have write permissions in the directory.

Compiler Not Found:
Install required compilers (g++/clang for Linux/Mac, MinGW for Windows).

Corrupted Data Files:
The program will create fresh files if they're missing.
Don't edit data files manually while the program is running.