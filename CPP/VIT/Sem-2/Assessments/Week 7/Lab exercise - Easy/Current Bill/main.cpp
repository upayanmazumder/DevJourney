#include <iostream>
#include <iomanip>
using namespace std;

class currentBill {
public:
    virtual double amount() = 0;
    virtual ~currentBill() {}
};

class Fan : public currentBill {
public:
    int watts, hours;
    Fan(int w, int h) : watts(w), hours(h) {}
    double amount() override {
        return (watts * hours) / 1000.0 * 1.5;
    }
};

class Light : public currentBill {
public:
    int watts, hours;
    Light(int w, int h) : watts(w), hours(h) {}
    double amount() override {
        return (watts * hours) / 1000.0 * 1.5;
    }
};

class TV : public currentBill {
public:
    int watts, hours;
    TV(int w, int h) : watts(w), hours(h) {}
    double amount() override {
        return (watts * hours) / 1000.0 * 1.5;
    }
};

int main() {
    int fWatt, fHour, lWatt, lHour, tWatt, tHour;
    cin >> fWatt >> fHour >> lWatt >> lHour >> tWatt >> tHour;

    Fan fan(fWatt, fHour);
    Light light(lWatt, lHour);
    TV tv(tWatt, tHour);

    double total = fan.amount() + light.amount() + tv.amount();

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}