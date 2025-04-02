#include <iostream>
using namespace std;

class UPSCInterviewScheduler {
public:
    void printSlot(const string& slot, const string& preferredSlot) {
        if (slot == preferredSlot)
            cout << "- " << slot << " (Preferred) " << endl;
        else
            cout << "- " << slot << " " << endl;
    }

    void printSlot(const string& slot) {
        cout << "- " << slot << " ";
    }
};

int main() {
    string slot1, slot2, slot3, preferredSlot;
    string slot4, slot5, slot6, preferredSlot2;

    cin >> slot1 >> slot2 >> slot3 >> preferredSlot;
    cin >> slot4 >> slot5 >> slot6 >> preferredSlot2;

    UPSCInterviewScheduler scheduler;

    cout << "Candidate 1: " << endl;
    scheduler.printSlot(slot1, preferredSlot);
    scheduler.printSlot(slot2, preferredSlot);
    scheduler.printSlot(slot3, preferredSlot);
    cout << endl;

    cout << "Candidate 2: " << endl;
    scheduler.printSlot(slot4, preferredSlot2);
    scheduler.printSlot(slot5, preferredSlot2);
    scheduler.printSlot(slot6, preferredSlot2);
    cout << endl;

    return 0;
}