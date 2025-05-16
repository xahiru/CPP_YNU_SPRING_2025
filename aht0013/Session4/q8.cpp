#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t = "", string a = "", int y = 0) : title(t), author(a), year(y) {}

    void display() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

int main() {
    int size;
    cout << "Enter number of books: ";
    cin >> size;

    Book* library = new Book[size];

    for (int i = 0; i < size; i++) {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore();
        getline(cin, library[i].title);
        cout << "Author: ";
        getline(cin, library[i].author);
        cout << "Year: ";
        cin >> library[i].year;
    }

    cout << "\nLibrary Contents:\n";
    for (int i = 0; i < size; i++) {
        library[i].display();
    }

    delete[] library;

    return 0;
}