#include <iostream>
#include <vector>
using namespace std;

class Event
{
    int id;
    string name;
    static int totalParticipants;

public:
    void setParticipant(int i, string n)
    {
        id = i;
        name = n;
        totalParticipants++;
    }
    int getParticipantID() { return id; }
    void display() { cout << "Participant found: Participant ID: " << id << ", Name: " << name << endl; }
    static int getTotalParticipants() { return totalParticipants; }
};

int Event::totalParticipants = 0;

int main()
{
    int n, id, searchID;
    string name;
    cin >> n;
    vector<Event> participants(n);
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        cin.ignore();
        getline(cin, name);
        participants[i].setParticipant(id, name);
    }
    cin >> searchID;
    for (auto &p : participants)
    {
        if (p.getParticipantID() == searchID)
        {
            p.display();
            return 0;
        }
    }
    cout << "Participant with ID " << searchID << " not found." << endl;
}