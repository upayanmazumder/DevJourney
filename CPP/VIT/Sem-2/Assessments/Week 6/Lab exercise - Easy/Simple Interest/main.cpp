#include <iostream>
#include <iomanip>
using namespace std;

class SimpleInterest {
private:
    double principal, rate, simpleInterest;
    int time;

public:
    SimpleInterest() : principal(0.0), rate(0.0), time(0), simpleInterest(0.0) {}

    SimpleInterest(double p, double r, int t) {
        principal = p;
        rate = r;
        time = t;
        simpleInterest = (principal * rate * time) / 100;
    }

    void display() {
        cout << fixed << setprecision(2) << simpleInterest << endl;
    }
};

int main() {
    double principal, rate;
    int time;

    cin >> principal >> rate >> time;

    SimpleInterest obj(principal, rate, time);
    obj.display();

    return 0;
}