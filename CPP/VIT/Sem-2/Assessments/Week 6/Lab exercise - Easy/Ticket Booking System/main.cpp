#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string event;
    int price;

public:
    Ticket(string event, int price) : event(event), price(price) {}
};

class ConcertTicket : public Ticket {
public:
    ConcertTicket(string event, int price) : Ticket(event, price) {}

    void displayConcertDetails() {
        cout << "Concert Details:\n";
        cout << "Event: " << event << "\n";
        cout << "Price: $" << price << "\n\n";
    }
};

class MovieTicket : public Ticket {
public:
    MovieTicket(string event, int price) : Ticket(event, price) {}

    void displayMovieDetails() {
        cout << "Movie Details:\n";
        cout << "Event: " << event << "\n";
        cout << "Price: $" << price << "\n";
    }
};

class Booking : public ConcertTicket, public MovieTicket {
public:
    Booking(string concertEvent, int concertPrice, string movieEvent, int moviePrice)
        : ConcertTicket(concertEvent, concertPrice), MovieTicket(movieEvent, moviePrice) {}

    void displayBookingDetails() {
        displayConcertDetails();
        displayMovieDetails();
    }
};

int main() {
    string concertEvent, movieEvent;
    int concertPrice, moviePrice;

    getline(cin, concertEvent);
    cin >> concertPrice;
    cin.ignore(); // Ignore newline after integer input
    getline(cin, movieEvent);
    cin >> moviePrice;

    Booking booking(concertEvent, concertPrice, movieEvent, moviePrice);
    booking.displayBookingDetails();

    return 0;
}