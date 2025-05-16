# Hangman Game (C++ Console Version)

## Compilation (on Ubuntu/Linux/Windows/Mac-os)
1. Ubuntu
```bash
g++ hangman.cpp -o hangman
./hangman
2. Windows 
g++ hangman.cpp -o hangman.exe
hangman.exe
3. Mac-os
clang++ hangman.cpp -o hangman
./hangman


## Description
This is a classic Hangman game implemented in C++ that runs in the terminal. The game randomly selects words from a dictionary file and challenges players to guess the word letter by letter before running out of attempts.

## Features
- Colorful terminal interface with ANSI color codes
- Three levels (Easy, Medium, Hard)
- Persistent score tracking across game sessions
- Prevention of duplicate guesses
- Clear display of guessed letters and remaining attempts
- Case-insensitive input handling

## Installation
1. Ensure you have a C++ compiler installed (g++ recommended)
2. Clone or download the repository

## How to Play
1. Select your difficulty level when prompted
2. Guess letters one at a time to reveal the hidden word
3. You have 6 incorrect attempts before losing the game
4. After each game, you can choose to play again or exit
5. Your wins and losses are tracked and saved between sessions

##  Levels
1. **Easy**: Words with 5 or fewer letters
2. **Medium**: Words between 6-8 letters
3. **Hard**: Words with more than 8 letters

## Score Tracking
The game automatically saves your score (wins and losses) to a `score.txt` file in the same directory. This file is created automatically if it doesn't exist.

## Customization
Word List: Edit `words.txt` to add/remove words (one word per line)
Appearance: Modify the ANSI color constants at the top of the file to change colors

## Known Issues
- Platform-dependent screen clearing (uses Linux `clear` command)
- Word file path is hardcoded in "words.txt"

