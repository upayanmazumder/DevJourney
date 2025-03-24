#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class LibraryItem {
protected:
    string dueDate, returnDate;

    // Function to calculate overdue days
    int calculateOverdueDays() {
        istringstream dueStream(dueDate), retStream(returnDate);
        int y1, m1, d1, y2, m2, d2;
        char dash;

        dueStream >> y1 >> dash >> m1 >> dash >> d1;
        retStream >> y2 >> dash >> m2 >> dash >> d2;

        // Convert to tm struct
        tm dueTm = {0, 0, 0, d1, m1 - 1, y1 - 1900};
        tm retTm = {0, 0, 0, d2, m2 - 1, y2 - 1900};

        // Convert to time_t
        time_t dueTime = mktime(&dueTm);
        time_t retTime = mktime(&retTm);

        // Calculate overdue days
        int overdueDays = (retTime - dueTime) / (60 * 60 * 24); // Convert seconds to days
        return max(0, overdueDays); // Ensure non-negative overdue days
    }

public:
    LibraryItem(string due, string ret) : dueDate(due), returnDate(ret) {}

    virtual int calculateFine() = 0; // Pure virtual function

    void displayFine() {
        cout << "Due Date: " << dueDate << endl;
        cout << "Return Date: " << returnDate << endl;
        cout << "Late Fine: " << calculateFine() << endl;
    }
};

class Book : public LibraryItem {
public:
    Book(string due, string ret) : LibraryItem(due, ret) {}

    int calculateFine() override {
        return calculateOverdueDays() * 1; // ₹1 per overdue day
    }
};

class DVD : public LibraryItem {
public:
    DVD(string due, string ret) : LibraryItem(due, ret) {}

    int calculateFine() override {
        return calculateOverdueDays() * 2; // ₹2 per overdue day
    }
};

int main() {
    string due, ret;
    cin >> due >> ret;

    Book book(due, ret);
    book.displayFine();

    DVD dvd(due, ret);
    dvd.displayFine();

    return 0;
}