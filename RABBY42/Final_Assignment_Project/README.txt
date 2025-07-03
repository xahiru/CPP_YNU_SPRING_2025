Compilation and Execution Instructions
=====================================

Overview
--------
The University Student Management System (USMS) is a C++ application designed to manage student, faculty, and course data.
This README provides step-by-step instructions to compile and run the program on both Unix/Linux and Windows systems.


Prerequisites
-------------
- Ensure a C++ compiler is installed:
  - On Unix/Linux: g++ (GNU Compiler Collection)
  - On Windows: MinGW-w64 or Microsoft Visual Studio with g++
- Required tools: make (for Makefile usage)


Directory Structure
-------------------
- include/: Contains header files (e.g., usms.h, person.h)
- src/: Contains source files (e.g., usms.cpp, person.cpp)
- data/: Contains data files (e.g., students.txt, faculty.txt)
- doc/: Contains documentation (e.g., README.txt, report.docx)


Compilation
-----------
1. Navigate to the project root directory (e.g., Final-project/).
2. Run the Makefile using the make command:
   - Unix/Linux: make
   - Windows (with MinGW): mingw32-make or make (if MinGW make is in PATH)
3. This will generate two executables:
   - ./usms (Unix/Linux)
   - ./usms.exe (Windows)


Execution
---------
- Unix/Linux: ./usms
- Windows: usms.exe (or ./usms.exe if in the same directory)
- The program will load existing data from the data/ folder and present a menu-driven interface.


System Features
---------------
1. Student Management
   - Add/View students
   - Track student details (name, ID, age, major, GPA)

2. Faculty Management
   - Add/View faculty members
   - Track faculty details (name, ID, age, department)

3. Course Management
   - Create courses
   - Assign faculty to courses
   - Enroll students in courses

4. Grade Management
   - Assign/update grades
   - Automatic GPA calculation
   - Grade reports (planned)

5. Data Persistence
   - Automatic load on startup
   - Automatic save after each operation

6. Exception Handling
   - Input validation (e.g., age range)
   - Error reporting
   - Notification system

7. Templates
   - NotificationQueue for system messages (planned)

8. Reports
   - Course enrollment lists (planned)
   - Student course lists (planned)
   - GPA ranking report (planned)


Sample Data Files
-----------------
Create these files in the data/ directory:

1. students.txt:
   # Format: ID,Name,Age,Major,GPA
   S001,John Doe,20,Computer Science,3.8
   S002,Jane Smith,21,Mathematics,3.9

2. faculty.txt:
   # Format: ID,Name,Age,Department
   F001,Dr. Alice Johnson,45,Computer Science
   F002,Prof. Bob Brown,50,Mathematics

3. courses.txt:
   # Format: Code,Title,FacultyID
   CSC101,Introduction to Programming,F001
   MAT201,Linear Algebra,F002

4. grades.txt:
   # Format: StudentID,CourseCode,Grade
   S001,CSC101,A
   S002,MAT201,B


Troubleshooting
---------------
- If compilation fails, ensure g++ and make are installed:
  - Ubuntu: sudo apt-get install g++ make
  - Windows: Install MinGW and add to PATH
- If data files are not found, create an empty data/ folder and ensure write permissions.
