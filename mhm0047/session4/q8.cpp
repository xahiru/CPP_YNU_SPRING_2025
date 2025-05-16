#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string director;
    int releaseYear;

public:
    Movie(string t = "", string d = "", int r = 0) : title(t), director(d), releaseYear(r) {}

    void setDetails(string t, string d, int r) {
        title = t;
        director = d;
        releaseYear = r;
    }

    void displayDetails() const {
        cout << "Title: " << title << ", Director: " << director << ", Year: " << releaseYear << endl;
    }
};

int main() {
    int size;
    cout << "Enter the number of movies: ";
    cin >> size;

    Movie* movieCollection = new Movie[size];

    for (int i = 0; i < size; i++) {
        string title, director;
        int year;
        
        cout << "\nEnter details for movie " << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore(); 
        getline(cin, title);
        
        cout << "Director: ";
        getline(cin, director);
        
        cout << "Release Year: ";
        cin >> year;

        movieCollection[i].setDetails(title, director, year);
    }

    cout << "\nMovie Collection:\n";
    for (int i = 0; i < size; i++) {
        movieCollection[i].displayDetails();
    }

    delete[] movieCollection;

    return 0;
}
