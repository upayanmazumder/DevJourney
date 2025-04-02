#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    void display() {
        cout << hours << "h " << minutes << "m " << endl;
    }

    Time& operator++() {
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours = (hours + 1) % 24;
        }
        return *this;
    }
};

int main() {
    int h, m;
    cin >> h >> m;
    Time t(h, m);
    t.display();
    ++t;
    t.display();
    return 0;
}