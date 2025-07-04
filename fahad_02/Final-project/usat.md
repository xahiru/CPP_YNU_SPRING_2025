# UNIVERSITY STUDENT ADMINISTRATION TOOL (USAT)

## Overview:
This is an all-in-one, menu-based application built using C++ and object-oriented principles, designed for managing students, faculty, courses, and academic records at a university level. The tool supports enrollment processes, grade tracking, GPA computation, and the generation of academic reports. ***

## Key Functionalities:
    → Manage student and faculty profiles

    → Course registration and administration

    → Input and modify grades, calculate GPA

    → Generate detailed academic and administrative reports

    → Store data persistently using local files

    → Robust error checking and input validation


## Technical Requirements:
    → Compatible with Linux, Unix, or Windows

    → Requires a C++ compiler (g++ is preferred)

    → At least 4GB of system memory

    → Minimum of 500MB available storage

## Setup Instructions:
**1. Confirm that g++ is installed:**

    → For Ubuntu/Debian: sudo apt-get install g++

    → For CentOS/RHEL: sudo yum install gcc-c++

    → On Windows: Install MinGW or use Windows Subsystem for Linux (WSL)

**2. Place the source file (test3.cpp) into your working directory.**

## How to Compile:
    → Open your terminal or command prompt.

    → Change to the folder containing test3.cpp.
    → Compile using the following command:
        g++ usat.cpp -o usat -std=c++11
## How to Run:
    → On Linux/Unix systems:
        ./usat
    → On Windows systems:
        usat.exe
## Data Files Used:
    → students.dat – Contains student data

    → faculty.dat – Stores faculty information

    → courses.dat – Holds course-related data

    → grades.dat – Keeps grade records

## Main Menu Options:
    → Register a new student

    → Add a new faculty member

    → Create a new course

    → Enroll a student in a course

    → Remove a student from a course

    → Enter or update a grade

    → List all registered students

    → List all faculty members

    → View all available courses

    → Show students enrolled in a specific course

    → Show courses assigned to a specific student

    → Generate GPA report for a student

    → Find students by name

    → Search courses by title

    → View alerts and notices

    → Exit the application

## Grade Conversion Table:
**Numerical scores are mapped to GPA grades as follows:**

    → 90–100 → A (4.0)

    → 80–89 → B (3.0)

    → 70–79 → C (2.0)

    → 60–69 → D (1.0)

    → <60 → F (0.0)