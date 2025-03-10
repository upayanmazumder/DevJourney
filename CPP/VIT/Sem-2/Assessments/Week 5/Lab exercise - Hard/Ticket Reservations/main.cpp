#include <iostream>
#include <vector>
using namespace std;

class Ticket
{
private:
    int ticketId;

public:
    Ticket(int id) : ticketId(id) {}

    int getId() const
    {
        return ticketId;
    }

    friend void cancelReservation(class Reservation &, const Ticket &);
};

class Reservation
{
private:
    vector<Ticket> reservedTickets;

public:
    Reservation(const vector<int> &ticketIds)
    {
        for (int id : ticketIds)
        {
            reservedTickets.emplace_back(id);
        }
    }

    void displayTickets() const
    {
        cout << "Reserved Tickets: ";
        for (const auto &ticket : reservedTickets)
        {
            cout << ticket.getId() << " ";
        }
        cout << endl;
    }

    friend void cancelReservation(Reservation &, const Ticket &);
};

void cancelReservation(Reservation &reservation, const Ticket &ticket)
{
    auto &tickets = reservation.reservedTickets;
    auto it = tickets.begin();

    while (it != tickets.end())
    {
        if (it->getId() == ticket.getId())
        {
            cout << "Ticket with ID " << ticket.getId() << " has been canceled." << endl;
            tickets.erase(it);
            reservation.displayTickets();
            return;
        }
        ++it;
    }

    cout << "Ticket with ID " << ticket.getId() << " not found in the reservation." << endl;
    reservation.displayTickets();
}

int main()
{
    int N, ticketToCancel;
    cin >> N;

    vector<int> ticketIds(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ticketIds[i];
    }
    cin >> ticketToCancel;

    Reservation reservation(ticketIds);
    reservation.displayTickets();

    Ticket cancelTicket(ticketToCancel);
    cancelReservation(reservation, cancelTicket);

    return 0;
}