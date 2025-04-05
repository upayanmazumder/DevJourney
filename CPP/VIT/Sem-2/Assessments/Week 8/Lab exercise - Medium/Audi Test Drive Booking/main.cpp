#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> slotAvailability;
    string date;
    int status;

    for (int i = 0; i < n; ++i) {
        cin >> date >> status;
        slotAvailability[date] = status;
    }

    string preferredDate;
    cin >> preferredDate;

    if (slotAvailability.count(preferredDate) && slotAvailability[preferredDate] == 1) {
        cout << "Test Drive Booked Successfully on " << preferredDate << endl;
    } else {
        cout << "Test Drive Slot not available on " << preferredDate << endl;
    }

    return 0;
}