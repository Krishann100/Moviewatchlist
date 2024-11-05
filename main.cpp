/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Movie {
    string title;
    int year;
    bool watched;

    Movie(string t, int y) : title(t), year(y), watched(false) {}
};

class MovieWatchlist {
private:
    vector<Movie> watchlist;

public:
    void addMovie() {
        string title;
        int year;
        cout << "Enter movie title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter release year: ";
        cin >> year;
        watchlist.push_back(Movie(title, year));
        cout << "Movie added successfully!" << endl;
    }

    void viewWatchlist() {
        if (watchlist.empty()) {
            cout << "Your watchlist is empty." << endl;
            return;
        }

        cout << "Your Movie Watchlist:" << endl;
        for (size_t i = 0; i < watchlist.size(); ++i) {
            cout << i + 1 << ". " << watchlist[i].title << " (" << watchlist[i].year << ")";
            if (watchlist[i].watched) {
                cout << " [Watched]";
            }
            cout << endl;
        }
    }

    void markAsWatched() {
        int index;
        viewWatchlist();
        cout << "Enter the number of the movie to mark as watched: ";
        cin >> index;
        if (index > 0 && index <= watchlist.size()) {
            watchlist[index - 1].watched = true;
            cout << "Movie marked as watched!" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    void deleteMovie() {
        int index;
        viewWatchlist();
        cout << "Enter the number of the movie to delete: ";
        cin >> index;
        if (index > 0 && index <= watchlist.size()) {
            watchlist.erase(watchlist.begin() + index - 1);
            cout << "Movie deleted from watchlist." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    void displayMenu() {
        cout << "\nMovie Watchlist Menu:\n";
        cout << "1. Add a Movie\n";
        cout << "2. View Watchlist\n";
        cout << "3. Mark as Watched\n";
        cout << "4. Delete a Movie\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;
            switch (choice) {
                case 1: addMovie(); break;
                case 2: viewWatchlist(); break;
                case 3: markAsWatched(); break;
                case 4: deleteMovie(); break;
                case 5: cout << "Exiting... Goodbye!" << endl; break;
                default: cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    MovieWatchlist app;
    app.run();
    return 0;
}
