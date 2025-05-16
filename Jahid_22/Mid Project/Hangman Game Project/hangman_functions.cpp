#include <iostream>
#include <vector>
#include "hangman_functions.h"
using namespace std;

void greet()
{
  cout << "============================\n";
  cout << "  Welcome to Hangman Game\n";
  cout << "============================\n";
  cout << "Instructions: Guess the letters to save the person from being hanged!\n";
  cout << "hangman", "developer", "cplusplus", "variable",
      "function", "looping", "terminal", "university", "keyboard",
      "internet", "computer", "debugger", "algorithm", "syntax",
      "compile", "project", "pointer", "execute", "hardware\n";
  cout << "You have 7 chances. Good luck!\n\n";
}

void display_misses(int misses)
{
  const string stages[] = {
      "  +---+\n  |   |\n      |\n      |\n      |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n =========\n",
      "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n =========\n"};
  cout << stages[misses];
}

void display_status(vector<char> incorrect, string answer)
{
  cout << "\nIncorrect Guesses: ";
  for (char c : incorrect)
  {
    cout << c << " ";
  }

  cout << "\n\nCodeword: ";
  for (char c : answer)
  {
    cout << c << " ";
  }
  cout << "\n";
}

void end_game(string answer, string codeword)
{
  cout << "\n============================\n";
  if (answer == codeword)
  {
    cout << "🎉 Hooray! You saved the person and guessed the word correctly!\n";
  }
  else
  {
    cout << "💀 Oh no! The man is hanged. The correct word was: " << codeword << "\n";
  }
  cout << "============================\n";
}
