#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author;
    int year;
public:
    void getData(int i) {
        cin.ignore();
        cout << "Enter Book " << i + 1 << " details:\n";
        cout << "\tTitle: ";
        getline(cin, title);
        cout << "\tAuthor: ";
        getline(cin, author);
        cout << "\tPublication year: ";
        cin >> year;
    }

    bool operator<=(const Book& b) const {
        return year <= b.year;
    }

    bool operator>=(const Book& b) const {
        return year >= b.year;
    }

    bool operator==(const string& t) const {
        return title == t;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book* books = new Book[n];
    for (int i = 0; i < n; ++i) {
        books[i].getData(i);
    }

    cin.ignore();
    string q;
    cout << "Enter title to search: ";
    getline(cin, q);

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (books[i] == q) {
            cout << "\nBook found:\n";
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }

    cout << "\nComparing...\n";
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (books[i] <= books[j] && !(books[j] <= books[i])) {
                cout << "Book " << i + 1 << " is older than Book " << j + 1 << ".\n";
            } else if (books[i] >= books[j] && !(books[j] >= books[i])) {
                cout << "Book " << i + 1 << " is newer than Book " << j + 1 << ".\n";
            } else {
                cout << "Book " << i + 1 << " and Book " << j + 1 << " were published in the same year.\n";
            }
        }
    }

    delete[] books;
    return 0;
}
