#include <iostream>

using namespace std;

class Time {
protected:
    int hours, minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    virtual void display() const {
        cout << "Time: " << hours << "h " << minutes << "m" << endl;
    }

    virtual ~Time() {}
};

class TimeToSeconds : public Time {
public:
    TimeToSeconds(int h, int m) : Time(h, m) {}

    void display() const override {
        cout << (hours * 3600 + minutes * 60) << " seconds" << endl;
    }
};

class TimeToMinutes : public Time {
public:
    TimeToMinutes(int h, int m) : Time(h, m) {}

    void display() const override {
        cout << (hours * 60 + minutes) << " minutes" << endl;
    }
};

int main() {
    int h, m;
    cin >> h >> m;

    Time original(h, m);
    TimeToSeconds timeInSeconds(h, m);
    TimeToMinutes timeInMinutes(h, m);

    original.display();
    timeInSeconds.display();
    timeInMinutes.display();

    return 0;
}